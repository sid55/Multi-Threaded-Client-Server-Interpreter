#ifndef myThread_h
#define myThread_h

#include <iostream>
#include <stdio.h>
#include "Thread.h"

using namespace std;

class myThread:public Thread{
public:	
	myThread(void *(*_threadRoutine) (void *) =NULL); 
	void *threadMainBody(void *args);
	~myThread();


};

#endif
