#Makefile

first: Thread.cpp myThread.cpp
	g++ -pthread -std=c++14 main2.cpp Thread.cpp myThread.cpp -o out 

all: client.cpp TCPSocket.cpp
	g++ -std=c++14 client.cpp TCPSocket.cpp -o client -pthread

all2: server.cpp TCPServerSocket.cpp TCPSocket.cpp Connection.cpp Thread.cpp
	g++ -pthread -std=c++14 server.cpp TCPServerSocket.cpp TCPSocket.cpp Connection.cpp Thread.cpp -o server

clean:
	rm server client client2 out
