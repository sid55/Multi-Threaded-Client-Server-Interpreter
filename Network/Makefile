#Makefile

all: client.cpp TCPSocket.cpp
	g++ -pthread -std=c++14 client.cpp TCPSocket.cpp -o client

all2: server.cpp TCPServerSocket.cpp TCPSocket.cpp
	g++ -pthread -std=c++14 server.cpp TCPServerSocket.cpp TCPSocket.cpp -o server

clean:
	rm server client
