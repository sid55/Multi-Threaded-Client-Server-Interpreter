#ifndef CHECK_CHAR_STRINGS_H
#define CHECK_CHAR_STRINGS_H
#include "common.h" 
class Check_Char_Strings{ //an exception to throw if the argument is a string or char 
    public: 
        Check_Char_Strings();
        void doPrint(); //prints the error and why it was an error 
        ~Check_Char_Strings();
};

#endif