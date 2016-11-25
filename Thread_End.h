#ifndef THREADEND_H
#define THREADEND_H

#include "Threads.h"

class Thread_End: public Threads{
    public:
        Thread_End();
        void doThread(vector<Var*>const&);
        Instruction *clone();
        ~Thread_End();
};

#endif