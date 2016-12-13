#ifndef THREADBEGIN_H
#define THREADBEGIN_H

#include "Threads.h"
#include "Thread.h"

class Thread_Begin: public Threads, public Thread{
    public:
        Thread_Begin();
        void doThread(vector<vector<Var*> >const&);
        void * threadMainBody (void * arg);
        Instruction *clone();
        ~Thread_Begin();
};

#endif
