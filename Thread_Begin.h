#ifndef THREADBEGIN_H
#define THREADBEGIN_H

#include "Threads.h"

class Thread_Begin: public Threads{
    public:
        Thread_Begin();
        void doThread(vector<Var*>const&);
        Instruction *clone();
        ~Thread_Begin();
};

#endif