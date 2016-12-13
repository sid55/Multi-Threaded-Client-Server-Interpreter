#ifndef UNLOCK_H
#define UNLOCK_H
#include "Threads.h"
class Unlock: public Threads{
    
    public:
        Unlock();
        ~Unlock();
        void doThreadMethod(vector<Var*>&);
        void checkOps(vector<Var*>const&);
        Instruction* clone();
};  

#endif
