#include "Thread_Begin.h"

Thread_Begin::Thread_Begin(){

}

void Thread_Begin::doThread(vector<Var*>const& vec) {
    pthread_t tid1;
	char msg1[] = "tid1";
	//pthread_create(&tid1, NULL, , (void*)msg1);
}

Instruction* Thread_Begin::clone(){
	Thread_Begin *threadb = new Thread_Begin();
	return threadb;
}

Thread_Begin::~Thread_Begin(){

}