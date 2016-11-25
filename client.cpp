/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>*/
#include "TCPSocket.h"
//using namespace std;

void terminate_with_error (int sock)
{
	if (sock != -1) // Close socket and exit is socket opened
	{
	    close (sock);
	    exit(1);
	}
}


int main (int argc,char ** argv)
{
	/*ifstream randfile("test.mis"); 

	//deleting the content of the .out file.
	ofstream outfile;
	outfile.open(".out",std::ofstream::trunc);
	outfile.close();

    if( randfile.peek() == std::ifstream::traits_type::eof()){ //this checks if the file is empty or not 
        std::cout << "failed" << std::endl; 
    }else{ //if not empty continue here 
        std::cout << "success" << std::endl;
    } */




	//char buffer[65536];
	if ( argc != 2) { // Check on the number of arguments and exit if incorrect
     	     printf ("Usage: ./client <server-address>\n");
             exit(1);
	}

	//unsigned int length = 1024;
	char source[1024];
	/*FILE *fp = fopen("test.mis", "r");
	if (fp != NULL) {
	    size_t newLen = fread(source, sizeof(char), 65536, fp);
	    if ( ferror( fp ) != 0 ) {
		fputs("Error reading file", stderr);
	    } else {
		source[newLen++] = '\0'; // Just to be safe. 
	    }

	    fclose(fp);
	}*/



	struct sockaddr_in serverAddr;
	std::cout << "Hi" << endl;
	TCPSocket *mySocket = new TCPSocket((char *)inet_ntoa(serverAddr.sin_addr),9999);

	//the code below adds content to the buffer
	char *mystr = "test.mis";
	strcpy(source,mystr);
	std::cout << "right below mis" << std::endl;
	if(int x = mySocket->writeToSocket(source,1023) < 0){
		std::cout << x << " this is the error value" << endl;
	}else{
		std::cout << "we are good to go" << endl;
	}


	//cout << "printing buffer below" <<endl;
	//printf("%s\n",buffer);

	//the val below is 65..7
	//int x = mySocket->writeToSocket(source,65536);

	/*while(mySocket->isPeerDisconnected()){
	   cout << "got into while loop" <<endl;
	   int y = mySocket->readFromSocket(buffer,65536);
	   cout << "the value of y is: " << y <<endl;
	}*/
	int y = mySocket->readFromSocketWithTimeout(source,1023,300,0);
	
	mySocket->shutDown();
	delete(mySocket);
	return 0;	
}
