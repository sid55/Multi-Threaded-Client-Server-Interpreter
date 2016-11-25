#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
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
	if ( argc != 2) { // Check on the number of arguments and exit if incorrect
		printf ("Usage: ./client <server-address>\n");
		exit(1);
	}




	char source[65536 + 1];
	FILE *fp = fopen("test.mis", "r");
	if (fp != NULL) {
	    size_t newLen = fread(source, sizeof(char), 65536, fp);
	    if ( ferror( fp ) != 0 ) {
		fputs("Error reading file", stderr);
	    } else {
		source[newLen++] = '\0'; /* Just to be safe. */
	    }

	    fclose(fp);
	}









	int sock; // Socket handler
	struct sockaddr_in serverAddr; // Server address
	socklen_t sin_size = sizeof(struct sockaddr_in); // get size of server address
	// Try to create a socket and print an error message and exit if failed
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("Error Creating Socket");
		exit(1);
	}
	memset((char *) &serverAddr, 0,sizeof(serverAddr)); // initialize the server address data structure
	 serverAddr.sin_family = AF_INET; // Set up the communication family
	 serverAddr.sin_port = htons(9999); //set the port of the server
	 struct hostent *server = gethostbyname(argv[1]); // convert the host name into a network host structure
	if ( server == NULL ) terminate_with_error(sock); // if failed terminate with an error message
// copy Server address data into server address structure
	memcpy((char *)&serverAddr.sin_addr.s_addr,(char *)server->h_addr, server->h_length);
	 memset(&(serverAddr.sin_zero), 0, 8); // Zero out the rest of the address structure
// try to connect to the server and exit with an error message if failed
	if (connect(sock,(sockaddr *)&serverAddr,sizeof(serverAddr)) == -1 ) terminate_with_error(sock);
	send (sock,source,65536,0); // Send a message to the server.
	close(sock);// Close the socket.

}
