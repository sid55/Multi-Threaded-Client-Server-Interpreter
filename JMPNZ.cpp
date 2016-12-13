#include "JMPNZ.h"
#include "InvalidArgument.h"
#include <fstream>

JMPNZ::JMPNZ(){

}

int JMPNZ::checkArgs(vector<Var*>const&vec){
	JUMP::checkOps(vec);
    int temp;
    if (dynamic_cast<Int*>(vec.at(2))){
         temp = vec.at(2)->getInt();
    }else if (dynamic_cast<String*>(vec.at(2))){
         Var* temp2 = getEntry(vec.at(2)->getString());
	 if (dynamic_cast<Int*>(temp2)){
		temp = temp2->getInt();
	 }else{
		try{
			throw InvalidArgument();
		}catch(InvalidArgument &e){
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have entered an invalid argument into the JMP" <<endl;
			exit(EXIT_SUCCESS);
		}
	 }
    }else{
	try{
		throw InvalidArgument();
	}catch(InvalidArgument &e){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid argument into the JMP" <<endl;
		exit(EXIT_SUCCESS);
	}
    }
//this is to check if the statement is zero or not to see which jmp method that class to proceed.
	if(temp != 0){
		return Label::doGet(vec);
	}else{
		return -99999;
	}
}

Instruction* JMPNZ::clone(){
	JMPNZ *j = new JMPNZ();
	return j;
}

JMPNZ::~JMPNZ(){

}

