#include "indexException.h"

IndexException::IndexException(int x) : num(x){}
void IndexException::print(){
    //this works with the set and get_str_char and throws an \
    exception if the user wants to go out of index. 
    std::cout << "Why are you going to " << num << " location" << endl;
}
IndexException::~IndexException(){}