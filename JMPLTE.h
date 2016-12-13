#ifndef JMPLTE_H
#define JMPLTE_H

#include "common.h"
#include "JUMP.h"
#include "label.h"
using namespace std;

class JMPLTE:public JUMP, public Label{
    public:
        JMPLTE();
        int checkArgs(vector<Var*>const&);
        Instruction* clone();	
        ~JMPLTE();
};
#endif
