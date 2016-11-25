#include "JUMP.h"

JUMP::JUMP(){

}

int JUMP::checkArgs(vector<Var*>const&vec){
	return 0;
}

void JUMP::checkOps(vector<Var*>const&vec){ //this checks on the instruction "jmp" and its variation, and see if the user or file has the right argument for them all.
											//it checks to see if the strings was also spelled correctly
     string myJMP = "JMP";
     string myJMPZ = "JMPZ";
     string myJMPNZ = "JMPNZ";
     string myJMPGT = "JMPGT";
     string myJMPLT = "JMPLT";
     string myJMPGTE = "JMPGTE";
     string myJMPLTE = "JMPLTE";
    if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMP)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=2){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }
    else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMPZ)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=3){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMPNZ)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=3){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMPGT)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMPLT)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMPGTE)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myJMPLTE)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     }else{
		int length = (int)vec.size();
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid instruction name" <<endl;
		exit(EXIT_SUCCESS);
	}	
}

Instruction* JUMP::clone(){
	return nullptr;
}

JUMP::~JUMP(){

}
