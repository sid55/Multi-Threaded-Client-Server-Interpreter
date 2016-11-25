#ifndef ASSIGN_H
#define ASSIGN_H

#include "Set.h"

class Assign:public Set{
public:
    Assign();
    void doSet(vector<Var*>const&vec,int);
    Instruction* clone();
    ~Assign();
};

#endif 
