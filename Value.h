#ifndef VALUE_H
#define VALUE_H
#include <iostream> 
#include <string> 
#include <fstream> 
#include "Set.h"
#include "map.h"
#include "checkToken.h"

class Value: public Set{
    public:
        Value();
        void doSet(vector<Var*>const&,int);
	Instruction* clone();
        ~Value();
};

#endif 
