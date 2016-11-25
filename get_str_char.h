#ifndef GET_STR_CHAR
#define GET_STR_CHAR 

#include "Char_Ops.h"

class GetChar: public Char_Ops {
  public:
    GetChar();
    void doChar_Ops(vector<Var*>const&);
    Instruction* clone();
    ~GetChar();
};

#endif 
