#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include "var.h"

using namespace std;

class String: public Var{
    private:
        string value;
    public:
        String(string);
        string getString();
        void setString(string);
        ~String();
};

#endif