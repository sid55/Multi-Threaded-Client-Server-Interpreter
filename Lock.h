#ifndef LOCK_H
#define LOCK_H
#include "Threads.h"

class Lock: public Threads{

    public: 
        Lock();
        ~Lock();
        void doThreadMethod(vector<Var*>&);
        void checkOps(vector<Var*>const&);
        Instruction* clone();
};

#endif 
