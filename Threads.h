#ifndef THREADS_H
#define THREADS_H

//#include "includes.h"
#include "instruction.h"


class Threads: public Instruction { //Thread class
	public:
		Threads();
		virtual void doThread(vector < vector<Var*> > &);
	 	virtual void doThreadMethod(vector<Var*>&);
		virtual Instruction* clone();
		~Threads();
};

#endif 
