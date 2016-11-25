#ifndef THREADS_H
#define THREADS_H

#include "includes.h"
#include "instruction.h"

class Threads: public Instruction { //Thread class
	public:
		Threads();
		virtual void doThread(vector<Var*>const&);
		virtual Instruction* clone();
		~Threads();
};

#endif 


