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
	void attack(Entity&);
};

void (*attack_)(Player*,Entity&);
void (*interact_)(Player*,Entity&);

void attack(Player*p,Entity&e){
	e.remove();
}
void interact(Player*p,Entity&e){
	attack_(*p,e);
}
JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*)&Player::attack, (void*) &attack, (void**) &attack_);
	MSHookFunction((void*)&Player::interact, (void*) &interact, (void**) &interact_);
	return JNI_VERSION_1_2;
}
