#ifndef JMPLT_H
#define JMPLT_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMPLT:public JUMP, public Label{
    public:
        JMPLT();
        int checkArgs(vector<Var*>const&);
        Instruction* clone();	
        ~JMPLT();
};
#endif
