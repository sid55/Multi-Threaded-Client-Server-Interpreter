#include "Connection.h"

Connection::Connection(TCPSocket * p_tcpSocket) : Thread(){
    tcpSocket = p_tcpSocket;
    next_connection = NULL;
}

void Connection::setNextConnection(Connection * connection){
    next_connection = connection; 
}

Connection * Connection::getNextConnection(){
    return next_connection;
}

Connection::~Connection(){
    if(tcpSocket != NULL){
        delete (tcpSocket);
    }
}

void * Connection::threadMainBody(void * arg){
    char file_name[1024];
    memset(file_name, 0, 1024);
    int read_bytes = tcpSocket->readFromSocket(file_name, 1023);
    cout << "BELOW THERE IS THE OUTPUT OF BUFFER (connection.cpp)" <<endl;
    printf("%s\n",file_name);

    if(read_bytes > 0) {        
        if( file_name[strlen(file_name)-1] == '\n' || file_name[strlen(file_name)-1] == '\r'){
            file_name[strlen(file_name)-1] = 0;
        }
        if( file_name[strlen(file_name)-1] == '\n' || file_name[strlen(file_name)-1] == '\r'){
            file_name[strlen(file_name)-1] = 0;
	}

        FILE* f = fopen(file_name, "r");

        if(f != NULL){
            fseek(f,0,2);
            long fsize = ftell(f);
            char * buffer = (char*)calloc(fsize+1, sizeof(char));
            fseek(f,0,0);
            fread(buffer,1,fsize,f);
            tcpSocket->writeToSocket(buffer,fsize);

	    //BELOW IS WHERE YOU CAN SEE THE OUPUT OF THE BUFFER
	    cout << "SHOWS BELOW IS MAGIC (connection.cpp)" <<endl;
	    printf("%s\n",buffer);

            free(buffer);
            fclose(f);
        }
        else{
            perror("Error With File\n");
            tcpSocket->writeToSocket("Error\n",6);
        }
    }
    tcpSocket->shutDown();
    return NULL;
}
