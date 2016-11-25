#ifndef BARRIER_H
#define BARRIER_H

#include "Threads.h"
class Barrier: public Threads{
    
    public: 
        Barrier();
        ~Barrier();
        void doThread(vector<Var*>const&);
        void checkOps(vector<Var*>const&);
        Instruction* clone();
};

#endif