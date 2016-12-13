#ifndef JMPGTE_H
#define JMPGTE_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMPGTE:public JUMP, public Label{
    public: 
        JMPGTE();
        int checkArgs(vector<Var*>const&);
         Instruction* clone();	
        ~JMPGTE();
};
#endif
