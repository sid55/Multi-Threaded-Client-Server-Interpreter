#include "sArgsException.h" 
using namespace std;
s_ArgsException::s_ArgsException(int x) : num(x){
}

void s_ArgsException::print(){
    std::cout << "why you gotta use " << num << " args?" << std::endl;
}
s_ArgsException::~s_ArgsException(){}