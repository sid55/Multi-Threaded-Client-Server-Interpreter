#ifndef DIV_H
#define DIV_H

#include "datatypes.h"
#include "Ops.h"
#include "map.h"
#include "divideException.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <cstring>
#include <limits>
#include <typeinfo>
using namespace std;

class Divide: public Ops{
    private:
        int totalInt;
        int countInts;
        int countDoubles;
        double totalDouble; 

    public:
        Divide();
	Instruction* clone();
       template<typename B, typename C>
        auto divideHelper(B second, C third){
            try{
                if(third == 0){
                    throw DivideException(0);
                }
                return second / third;
            }catch(DivideException & zero){
                ofstream outputFile;
                outputFile.open(".err");
                outputFile << "You can't divide by 0" << endl; //later on, add this into the divideException class
                exit(EXIT_SUCCESS);
                //return (decltype(second+third)) 0;
            }
        }
        void doOps(vector<Var*>const&);
        ~Divide();
};


#endif
