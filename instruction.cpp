#include "instruction.h"

Instruction::Instruction(){

}

Instruction* Instruction::clone(){
    return nullptr;
}

void Instruction:: doOps(vector<Var*>const&){

}

void Instruction:: doChar_Ops(vector<Var*>const&){

}

void Instruction:: doMisc(vector<Var*>const&){

}

void Instruction:: doSet(vector<Var*>const&,int garbage){

}

int Instruction:: doGet(vector<Var*>const&){
    return 0;
}

int Instruction:: checkArgs(vector<Var*>const&){
	return 0;    
}

void Instruction:: doThread(vector<Var*>const&){
    
}

/*void doJMP(){}
void doChar_Ops(){}
void doMisc(){}
void doSet(){}*/
Instruction::~Instruction(){

}


