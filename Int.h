#ifndef INT_H
#define INT_H
 
#include <iostream>
#include "var.h"

class Int: public Var{
    private:
        int value;
    public:
        Int(int);
        int getInt();
        void setInt(int);
        ~Int();
};

#endif