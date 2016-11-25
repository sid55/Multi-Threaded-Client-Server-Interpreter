#ifndef INDEXEXCEPTION_H
#define INDEXEXCEPTION_H
#include "common.h"
class IndexException{
    public:
        int num;
        IndexException(int);
        void print();
        ~IndexException();
};

#endif