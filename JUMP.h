#ifndef JUMP_H
#define JUMP_H
#include "instruction.h"
#include <iostream>
#include <string> 
#include <fstream>

class JUMP: virtual public Instruction{
    public:
        JUMP();
        virtual int checkArgs(vector<Var*>const&);
        virtual void checkOps(vector<Var*>const&); 
        virtual Instruction* clone();
       ~JUMP();
};
#endif
