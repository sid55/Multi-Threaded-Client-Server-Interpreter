#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include <stdio.h>
#include <vector>
#include "map.h"
#include "var.h"
#include "Set.h"

using namespace std;

class Label: public Set{
int counter;
   public:
	Label();
	void doSet(vector<Var*>const&,int);
	int doGet(vector<Var*>const&);
	int getCounter();
 	void increaseCounter();
	void setCounter(int);
        Instruction* clone();	
	~Label();
};
#endif
