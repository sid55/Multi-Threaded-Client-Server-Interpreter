#ifndef SET_STR_CHAR_H
#define SET_STR_CHAR_H
#include <string> 
#include <iostream>
#include "Char_Ops.h"
#include "map.h"

class SetChar:public Char_Ops {
  public:
    SetChar();
    void doChar_Ops(vector<Var*>const&);
    virtual Instruction* clone();
    ~SetChar();
};

#endif 
