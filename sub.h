#ifndef SUB_H
#define SUB_H
#include "Ops.h"
#include "common.h"
#include <iostream>

//the function only takes up to three with the first type that takes the result of the next two.
using namespace std;

class Subtract: public Ops {
    private:
        int totalInt;
        int countInts;
        int countDoubles;
        double totalDouble; 

  public:
    Subtract();
    Instruction* clone();
    template <typename B, typename C>
    auto subtractHelper(B b, C c) {
        return b - c;
    }
    void doOps(vector<Var*>const&);
    ~Subtract();
};

#endif
