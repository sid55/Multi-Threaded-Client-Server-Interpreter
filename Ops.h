#ifndef OPS_H
#define OPS_H
#include <iostream>
#include <fstream> 
#include <string>
#include "instruction.h"
#include "map.h"

using namespace std;

class Ops : public Instruction{ //the superclass for operation functions: add, sub, divide, and mult.
  public:
    Ops();
    virtual void doOps(vector<Var*>const&);
    virtual void checkOps(vector<Var*>const&);
    virtual Instruction* clone(); //creates a clone that is necessary of Instruction object 
    ~Ops();
};

#endif

