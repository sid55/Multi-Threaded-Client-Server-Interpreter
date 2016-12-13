#include "Thread.h"
#include "TCPSocket.h"
#include "map.h"
class Connection : public Thread{
    private: 
        TCPSocket * tcpSocket;
        Connection * next_connection; 
    public:
        Connection(TCPSocket * p_tcpSocket);
        void * threadMainBody(void * arg);
        void setNextConnection(Connection * connection);
        Connection * getNextConnection();
        ~Connection();
};
