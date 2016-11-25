#include "myThread.h"


myThread::myThread(void *(*_threadRoutine) (void *)):Thread(_threadRoutine){
	cout << "in thread constructor" <<endl;	

}


void *myThread::threadMainBody(void *arg){
cout << "in main body of myThread" <<endl;
return nullptr;
}

myThread::~myThread(){

}

