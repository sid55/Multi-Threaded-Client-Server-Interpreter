#include "Thread_End.h"

Thread_End::Thread_End(){

}

void Thread_End::doThread(vector<Var*>const& vec) {

}

Instruction* Thread_End::clone(){
	Thread_End *threade = new Thread_End();
	return threade;
}

Thread_End::~Thread_End(){
    
}