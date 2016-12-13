#include "Ops.h"

Ops::Ops(){
    
}

void Ops::doOps(vector<Var*>const&vec){

}

Instruction* Ops::clone(){
	return nullptr;
}

void Ops::checkOps(vector<Var*>const&vec){
     string myAdd = "ADD";
     string mySub = "SUB";
     string myDiv = "DIV";
     string myMult = "MUL";

     if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myAdd)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length<4 || length>14){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the ADD instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	//this checks the parameter at index 2 because 0 and 1 are type strings. 
	//it checks to see if the parameters are int or double.
	for(int i = 2; i < length; i++){
		if(dynamic_cast<Int*>(vec.at(i)) || dynamic_cast<Double*>(vec.at(i))){
		}else if(dynamic_cast<String*>(vec.at(i))){
			//if it is a variable, check if it is a String type or int or double 
			try{
				//reasoning is at the next if statement due to having no idea on differentiating \
				between string classs and string due to dam std::oor.
				string tempString = vec.at(i)->getString();
				Var * tempData = myMap.at(tempString);
				if(dynamic_cast<Double*>(tempData) || dynamic_cast<Int*>(tempData)){
				}
			}catch(const std::out_of_range& goddam){
				ofstream outputFile;
				outputFile.open(".err");
				outputFile << "You did not enter either a NUMERIC or a REAL type for ADD" << endl;
				exit(EXIT_SUCCESS);
			}
		}
	}
     }
    else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myMult)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length<4 || length>14){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the MUL instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	for(int i = 2; i < length; i++){
		if(dynamic_cast<Int*>(vec.at(i)) || dynamic_cast<Double*>(vec.at(i))){
			//does nothing here if it's an Int or Double '
		}else if(dynamic_cast<String*>(vec.at(i))){
			//if it is a variable, check if it is a String type or int or double 
			try{
				//no idea how to differentiate between String variable and String \
				so try and catch was the only solution because i was getting std::out_of_range
				string tempString = vec.at(i)->getString();
				Var * tempData = myMap.at(tempString);
				if(dynamic_cast<Double*>(tempData) || dynamic_cast<Int*>(tempData)){
					//same concept as the overhead if statement 
				}
			}catch(const std::out_of_range& goddam){
				ofstream outputFile;
				outputFile.open(".err");
				outputFile << "You did not enter either a NUMERIC or a REAL type for MUL" << endl;
				exit(EXIT_SUCCESS);
			}
		}
	}
     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(mySub)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length<4 || length>4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the SUB instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	for(int i = 2; i < length; i++){
		if(dynamic_cast<Int*>(vec.at(i)) || dynamic_cast<Double*>(vec.at(i))){
		}else if(dynamic_cast<String*>(vec.at(i))){
			try{
				string tempString = vec.at(i)->getString();
				Var * tempData = myMap.at(tempString);
				if(dynamic_cast<Double*>(tempData) || dynamic_cast<Int*>(tempData)){
				}
			}catch(const std::out_of_range& goddam){
				ofstream outputFile;
				outputFile.open(".err");
				outputFile << "You did not enter either a NUMERIC or a REAL type for SUB" << endl;
				exit(EXIT_SUCCESS);
			}
		}
	}

     }
   else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myDiv)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length<4 || length>4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the DIV instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	for(int i = 2; i < length; i++){
		if(dynamic_cast<Int*>(vec.at(i)) || dynamic_cast<Double*>(vec.at(i))){

		}else if(dynamic_cast<String*>(vec.at(i))){
			try{
				string tempString = vec.at(i)->getString();
				Var * tempData = myMap.at(tempString);
				if(dynamic_cast<Double*>(tempData) || dynamic_cast<Int*>(tempData)){
				}
			}catch(const std::out_of_range& goddam){
				ofstream outputFile;
				outputFile.open(".err");
				outputFile << "You did not enter either a NUMERIC or a REAL type for DIV" << endl;
				exit(EXIT_SUCCESS);
			}
		}
	}	
     }
   else{
	int length = (int)vec.size();	
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid instruction name" <<endl;
		exit(EXIT_SUCCESS);
	}
}

Ops::~Ops(){

}


