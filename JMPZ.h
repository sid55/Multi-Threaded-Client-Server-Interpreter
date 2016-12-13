#ifndef JMPZ_H
#define JMPZ_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMPZ:public JUMP, public Label{
    public:
        JMPZ();
        int checkArgs(vector<Var*>const&);
        Instruction* clone();	
        ~JMPZ();
};
#endif
