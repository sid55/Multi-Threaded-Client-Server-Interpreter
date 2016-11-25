#ifndef CHAR_H
#define CHAR_H

#include <iostream>
#include "var.h"

using namespace std;

class Char: public Var{
    private:
        char value;
    public:
        Char(char);
        char getChar();
        void setChar(char);
        ~Char();
};

#endif
