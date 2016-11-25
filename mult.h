#ifndef MULT_H
#define MULT_H

#include "datatypes.h"
#include "Ops.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cstring>


using namespace std;

//this one focuses on variadic templates in method

class Multiply: public Ops {
    private:
    int totalInt;
    int countInts;
    int countDoubles;
    double totalDouble;  

  public:
   Multiply();
   Instruction* clone();
   void doOps(vector<Var*>const&);
    ~Multiply();
};

#endif
