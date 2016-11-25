#ifndef JMP_H
#define JMP_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMP:public JUMP, public Label{
    public:
        JMP();
        int checkArgs(vector<Var*>const&);
        Instruction* clone();	
        ~JMP();
};
#endif
