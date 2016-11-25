#ifndef MISC_H
#define MISC_H
#include "instruction.h"
#include <iostream> 
#include <string> 
#include <fstream>

class Misc : public Instruction{
    public:
        Misc();
        virtual void doMisc(vector<Var*>const&);//an empty holder for the virtual function of doMisc.
	virtual void checkOps(vector<Var*>const&);
        virtual Instruction* clone();
        ~Misc();
};

#endif
