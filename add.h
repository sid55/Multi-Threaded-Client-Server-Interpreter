#ifndef ADD_H
#define ADD_H

#include "datatypes.h"
#include "Ops.h"
#include "map.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <cstring>

using namespace std;

class Add: public Ops {
  private:
    int totalInt;
    int countInts;
    int countDoubles;
    double totalDouble;  

  public:
   Add();
   void doOps(vector<Var*>const&); //Var is the object that holds the types the assignment requires
   Instruction *clone();
  ~Add();
};

#endif
