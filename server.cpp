/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>*/
#include "TCPServerSocket.h"
//#include "Connection.h"
#include "Thread.h"
#include "TCPSocket.h"
#include "map.h"
#include "GarbageCollector.h"
// A function to print an error message and terminate
void terminate_with_error (const char * error_msg,int sock)
{
	printf ("%s\n",error_msg); // printing error
	perror("Socket Error:"); // printing system error
	if (sock != -1) // Close socket and exit is socket opened
	{
	    close (sock);
	    exit(1);
	}
}

int main (int argc,char ** argv){
 
  struct sockaddr_in serverAddr;




  TCPServerSocket *tcpServerSocket = new TCPServerSocket("0.0.0.0",9999,5);
  GarbageCollector * garbageCollector = new GarbageCollector();
  bool x = tcpServerSocket->initializeSocket();
  cout << x <<endl;
  cout << true <<endl;
  for(;;){
    TCPSocket *tcpSocket = tcpServerSocket->getConnection();
    cout << "no errors bruh yet" <<endl;
    if(tcpSocket == NULL) break;
    garbageCollector->cleanup();
    cout << "no errors until here" <<endl;
    Connection *c = new Connection(tcpSocket);
    c->start();
    garbageCollector->addConnection(c);
  }
  delete(garbageCollector);
  delete(tcpServerSocket);
  return 0;
}	
