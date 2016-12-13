#ifndef SLEEP_H
#define SLEEP_H
#include "Misc.h"
#include <thread> 
#include <chrono>

class Sleep:public Misc{
    public:
        Sleep();
        void doMisc(vector<Var*>const&);
        virtual Instruction* clone();
        ~Sleep();
};

#endif