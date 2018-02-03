#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

class Entity{
	public:
	void remove();
};
class Player:public Entity{};

class GameMode{
	public:
	void attack(Player&,Entity&);
	void interact(Player&,Entity&);
};

void (*attack_)(void*,Player&,Entity&);
void (*interact_)(void*,Player&,Entity&);

void attack(void*thiz,Player&p,Entity&e){
	e.remove();
}
void interact(void*thiz,Player&p,Entity&e){
	interact_(thiz,p,e);
}
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&GameMode::attack, (void*) &attack, (void**) &attack_);
	MSHookFunction((void*)&GameMode::interact, (void*) &interact, (void**) &interact_);
	return JNI_VERSION_1_2;
}
