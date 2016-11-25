#ifndef CHAR_OPS_H
#define CHAR_OPS_H
#include <iostream> 
#include <string> 
#include <fstream>
#include "instruction.h"
class Char_Ops: public Instruction{
    public: 
        Char_Ops(); 
        void doChar_Ops(vector<Var*>const&);
	virtual void checkOps(vector<Var*>const&);
        virtual Instruction* clone();
        ~Char_Ops();
};

#endif 
