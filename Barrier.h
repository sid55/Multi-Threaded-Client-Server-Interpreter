#ifndef BARRIER_H
#define BARRIER_H

#include "Threads.h"
class Barrier: public Threads{
    
    public: 
        Barrier();
        ~Barrier();
        void doThreadMethod(vector<Var*>&);
        void checkOps(vector<Var*>const&);
        Instruction* clone();
};

#endif
