#ifndef THREADEND_H
#define THREADEND_H

//#include "Threads.h"
//#include "Thread.h"

#include "common.h"

class Thread_End: public Threads, public Thread{
    public:
        Thread_End(void *(*_threadRoutine) (void *) =NULL);
        // Thread_End(const Var&);
        vector< vector<Var*> > tVec;
        void doThread(vector < vector<Var*> > &);
        void * threadMainBody (void * arg);
        Instruction *clone();
        ~Thread_End();
};

#endif
