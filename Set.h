#ifndef SET_H 
#define SET_H  
#include <iostream> 
#include <string>
#include <fstream> 
#include "instruction.h"

class Set : virtual public Instruction{
    public: 
        Set();
        virtual void doSet(vector<Var*>const&,int);
        virtual int doGet(vector<Var*>const&); //will be used for label
	virtual void checkOps(vector<Var*>const&);
        virtual Instruction* clone();
        ~Set();
};

#endif 
