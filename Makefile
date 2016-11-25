#Makefile

CC := g++
CFLAGS := -std=c++14
TARGET := server#test
LDFLAGS := -lpthread
LFLAGS := -pthread 

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(filter-out client.cpp main.cpp, $(wildcard *.cpp))
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

allj: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $(LFLAGS)
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean
 
client: client.cpp TCPSocket.cpp
	g++ -pthread -std=c++14 client.cpp TCPSocket.cpp -o client


all: labelmain.cpp label.h label.cpp
	g++ -std=c++14 labelmain.cpp label.cpp -o myMain
	./myMain
	rm myMain

all2: tokenizer.cpp add.cpp checkToken.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp Ops.cpp instruction.cpp
	g++ -std=c++14 tokenizer.cpp add.cpp checkToken.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp Ops.cpp instruction.cpp -o myMain
	./myMain
	rm myMain

all3: checkToken.cpp
	g++ -std=c++14 checkToken.cpp -o myMain
	./myMain
	rm myMain

all4: main.cpp Int.cpp Double.cpp var.cpp map.cpp add.cpp
	g++ -std=c++14 main.cpp Int.cpp Double.cpp var.cpp map.cpp add.cpp -o myMain
	./myMain
	rm myMain

all5: 
	g++ -std=c++14 out.cpp checkToken.cpp map.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp InvalidArgument.cpp -o myMain
	./myMain
	rm myMain

all6: JMPNZ.cpp map.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp InvalidArgument.cpp
	g++ -std=c++14 JMPNZ.cpp map.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp InvalidArgument.cpp -o test
	./test
	rm test

all7: add.cpp map.cpp Ops.cpp instruction.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp InvalidArgument.cpp
	g++ -std=c++14 add.cpp map.cpp Ops.cpp instruction.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp InvalidArgument.cpp -o test
	./test
	rm test

allVars: #main.cpp map.cpp var.cpp Int.cpp Double.cpp String.cpp

	g++ -std=c++14 main.cpp map.cpp var.cpp Int.cpp Double.cpp String.cpp Char.cpp add.cpp Ops.cpp mult.cpp div.cpp divideException.cpp instruction.cpp checkToken.cpp JMP.cpp Misc.cpp set_str_char.cpp Char_Ops.cpp Set.cpp -o test

git: 
	git add -A
	git commit
	git push
