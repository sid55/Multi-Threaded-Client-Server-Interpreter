#ifndef JMPNZ_H
#define JMPNZ_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMPNZ:public JUMP, public Label{
    public:
        JMPNZ();
        int checkArgs(vector<Var*>const&);
        Instruction* clone();
        ~JMPNZ();	
};
#endif
