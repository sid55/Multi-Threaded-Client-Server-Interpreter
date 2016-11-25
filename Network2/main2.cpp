/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>*/
//#include "TCPServerSocket.h"
//#include "TCPSocket.h"
//#include "Connection.h"
#include "myThread.h"
#include "Thread.h"
#include "includes.h"
#include <iostream> 
//#include <string> 
//#include <pthread.h>
//#include <stdlib.h> 
//#include <stdio.h>


using namespace std; 

//  void * print(void*){
//  	cout << "I'm here now in print()" << endl;
//  }

void* runner(void *temp){
	cout << "hello" <<endl;
	return nullptr;
}

// A function to print an error message and terminate
int main (int argc,char ** argv){
	cout << "in the main" <<endl;
	int limit = 5;
	void* x = &limit; 
	Thread *t = new myThread(runner);
	t->start();
	//t->run(t);
	delete t;
	return 0;	
}	
