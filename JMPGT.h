#ifndef JMPGT_H
#define JMPGT_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMPGT:public JUMP, public Label{
    public:
        JMPGT();
        int checkArgs(vector<Var*>const&);
        ~JMPGT();
        Instruction* clone();
};
#endif
