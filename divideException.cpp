#include "divideException.h"
//this is to create a class of this if an exception is thrown in order for it to output an error and end program. 
DivideException::DivideException(int x){
    divisor = x;
}

DivideException::~DivideException(){}
