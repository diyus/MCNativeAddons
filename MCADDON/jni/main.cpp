#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

class Entity{
	public:
	void remove();
};
class Player:public Entity{
	public:
	void interact(Entity&);
};

class GameMode{
	public:
	void attack(Player&,Entity&);
	void interact(Player&,Entity&);
};

GameMode*gm;

void (*attack_)(void*,Player&,Entity&);
void (*interact_)(Player*,Entity&);

void attack(void*thiz,Player&p,Entity&e){
	e.remove();
	gm = thiz;
}
void interact(Player*p,Entity&e){
	attack_(gm,*p,e);
}
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&GameMode::attack, (void*) &attack, (void**) &attack_);
	MSHookFunction((void*)&Player::interact, (void*) &interact, (void**) &interact_);
	return JNI_VERSION_1_2;
}
