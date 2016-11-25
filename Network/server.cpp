/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>*/
#include "TCPServerSocket.h"
#include "TCPSocket.h"
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
   	char buffer[65536];	

	//char const& myname2 = NULL;
	//TCPServerSocket *myTCP = new TCPServerSocket((char *)inet_ntoa(serverAddr.sin_addr),9999,5);
	TCPServerSocket *myTCP = new TCPServerSocket("0.0.0.0",9999,5);

	bool val = myTCP->initializeSocket();
	cout << val << endl;
	cout << true<<endl;

	TCPSocket *mySocket = myTCP->getConnection();
	cout << "after get conection " <<endl;
		
	int x = mySocket->writeToSocket(buffer, 65536);
	cout << "x is: " <<x<<endl;
	long y = mySocket->getStreamOutSize();
	cout << "y is: " <<y<<endl;

	//while(!mySocket->isPeerDisconnected()){	
	//cout << "got into peer disconnected if statement" <<endl;

	//Not Gonna change code, put socket stuff into buffer
	//For printing out buffer onto server side
	int z = mySocket->readFromSocketWithTimeout(buffer, 65535,20,0);
	//cout << "the value inside if is" <<z<<endl;
	//}
	//NEED TO DO BELOW STATMENT
	//mySocket->setPeerDisconnected(true);	

	printf("%s\n",buffer);
	mySocket->shutDown();	
	delete(mySocket); 	
	delete(myTCP);
	return 0;
}	
