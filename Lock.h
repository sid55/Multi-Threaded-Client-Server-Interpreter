#ifndef LOCK_H
#define LOCK_H
#include "Threads.h"

class Lock: public Threads{

    public: 
        Lock();
        ~Lock();
        void doThread(vector<Var*>const&);
        void checkOps(vector<Var*>const&);
        Instruction* clone();
};

#endif 