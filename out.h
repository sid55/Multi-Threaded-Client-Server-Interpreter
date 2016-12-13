#ifndef OUT_H
#define OUT_H
#include <iostream>
#include <fstream>
#include "Misc.h"
#include "checkToken.h"

using namespace std;

class Out:public Misc{
    public:
        Out();
        void doMisc(vector<Var*>const&);
	void addStrChar(string);
	Instruction* clone();
        ~Out();
};

#endif
