#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "var.h" 
#include "datatypes.h"
#include "map.h"

#include <iostream>
#include <vector> 
#include <string>
#include <fstream>
#include <cstring>

using namespace std;
//basically the superclass that supercedes every class and the parent
class Instruction{
    public:
        Instruction();
        virtual void doOps(vector<Var*>const&);
        virtual void doChar_Ops(vector<Var*>const&);
        virtual void doMisc(vector<Var*>const&);
        virtual void doSet(vector<Var*>const&,int);
	virtual int doGet(vector<Var*>const&);
	virtual int checkArgs(vector<Var*>const&);
        //virtual void checkOps(vector<Var*>const&);
        virtual void doThread(vector<Var*>const&);
	virtual Instruction* clone();
        ~Instruction();
};

#endif
