#include "Misc.h"

Misc::Misc(){

}

void Misc::doMisc(vector<Var*>const&vec){
    
}
//error checking to see if they spelled the arguments right and have the right number of arguments.
//once that is set, it will continue on with the classes.
void Misc::checkOps(vector<Var*>const&vec){
     string mySleep = "SLEEP";
     string myOut = "OUT";
    if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(mySleep)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=2){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	if(dynamic_cast<Int*>(vec.at(1))){
		//checking to see if the index 1 is a int or not 
	}else{
		//send an error if it is not an int 
		ofstream outputFile; 
		outputFile.open(".err");
		outputFile << "You have entered a non-int argument for SLEEP instruction" << endl;
		exit(EXIT_SUCCESS);
	}
	
     } else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myOut)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length<2 || length>13){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
     } else{
		int length = (int)vec.size();
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid instruction name" <<endl;
		exit(EXIT_SUCCESS);
	} 
}

Instruction* Misc::clone(){
	return nullptr;
}


Misc::~Misc(){

}
