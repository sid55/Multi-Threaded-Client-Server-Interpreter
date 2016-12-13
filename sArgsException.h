#ifndef SARGSEXCEPTION_H
#define SARGSEXCEPTION_H
#include "common.h"
class s_ArgsException{
    public:
        int num;
        s_ArgsException(int); //only works if the length of the arguments is wrong or invalid with the parameter pack
        void print();
        ~s_ArgsException();
};

#endif