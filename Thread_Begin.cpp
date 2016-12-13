#include "Thread_Begin.h"

Thread_Begin::Thread_Begin(){

}


void Thread_Begin::doThread(vector < vector<Var*> >const&vec) {
    // pthread_t tid1;
	// char msg1[] = "tid1";
	//vector <Var*> tempVec = vec.at(0);
	//cout << tempVec.at(0)->getString() << endl;
	//cout << "Calling Thread_Begin in doThread" << endl;
}

void* Thread_Begin::threadMainBody (void * arg){
	return nullptr; 
}

Instruction* Thread_Begin::clone(){
	Thread_Begin *threadb = new Thread_Begin();
	return threadb;
}

void *threadMainBody(void *arg){
	return nullptr;
}

Thread_Begin::~Thread_Begin(){

}
