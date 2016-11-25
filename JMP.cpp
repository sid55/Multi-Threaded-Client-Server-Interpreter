#include "JMP.h"
#include "InvalidArgument.h"
#include <fstream>
JMP::JMP(){

}

int JMP::checkArgs(vector<Var*>const&vec){
	JUMP::checkOps(vec);
	return Label::doGet(vec);
}

Instruction* JMP::clone(){
	JMP *j = new JMP();
	return j;
}

JMP::~JMP(){
	
}

