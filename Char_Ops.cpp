#include "Char_Ops.h"

Char_Ops::Char_Ops(){

}

void Char_Ops::doChar_Ops(vector<Var*>const&vec){
    
}
//checking the argument and throw exception to their respective problems into an output file called 'err'
void Char_Ops::checkOps(vector<Var*>const&vec){
     string mySet = "SET_STR_CHAR";
     string myGet = "GET_STR_CHAR";
     if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(mySet)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	//this checks if the index selected is out of range for current variable.
	if(dynamic_cast<String*>(vec.at(1))){	
		Var* tmp = getEntry(vec.at(1)->getString());
		string temp3 = (string)(tmp->getString());
		int size = getEntry2(vec.at(1)->getString());
		if(vec.at(2)->getInt() > size){
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have entered an out of range index" << endl;
			exit(EXIT_SUCCESS);			
		}else if(dynamic_cast<Int*>(vec.at(2))){
			//test if there is an int at index argument if not then it'll send an error '
		}else{
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have entered a non-int value in index" << endl;
			exit(EXIT_SUCCESS);				
		}

		if(dynamic_cast<Char*>(vec.at(3)) || dynamic_cast<String*>(vec.at(3))){
			//check if the third index is a char or a string "var"
			if(dynamic_cast<String*>(vec.at(3))){
				try{
					string tempString = vec.at(3)->getString();
					Var * tempData = myMap.at(tempString);
					//checks if it is a var and not just a random string 
				}catch(const std::out_of_range& goddam){ 
					//if it's a legit string then i can't access the map and it'll give me out of range error '
					ofstream outputFile;
					outputFile.open(".err");
					outputFile << "You inserted a string at index 3 for SET_STR_CHAR" << endl;
				}
			}
		}else if(dynamic_cast<Int*>(vec.at(3)) || dynamic_cast<Double*>(vec.at(3))){
			//assuming everything else besides char and string 
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You inserted a non-CHAR type in index 3 of SET_STR_CHAR" << endl;
			exit(EXIT_SUCCESS);
		}
	}else if(dynamic_cast<Int*>(vec.at(1)) || dynamic_cast<Double*>(vec.at(1)) || dynamic_cast<Char*>(vec.at(1))){
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You inserted a non-STRING type in index 1 of SET_STR_CHAR" << endl;
			exit(EXIT_SUCCESS);
	}
     }

	 //GET_STR_CHAR HERE
    else if ((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myGet)==0))){ //|| (vec.at(0)->getString.compare(myMult)==1))){
	int length = (int)vec.size();
	if(length!=4){
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
	}
	if(dynamic_cast<String*>(vec.at(1))){ //have to convert it to string in order to obtain the size of the string to compare against the index
		int tmp = getEntry2(vec.at(1)->getString());
		//cout << tmp << " right here" << endl; //should give me 100
		//cout << vec.at(2)->getInt() << "this is the index I want to select" << endl;
		//string temp3 = (string)(tmp->getString());
		if(vec.at(2)->getInt() > tmp){
			//cout << " im here 1 " << endl;
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have entered an out of range index" << endl;
			exit(EXIT_SUCCESS);
		}else if(dynamic_cast<Int*>(vec.at(2))){
			//cout << "im here 2 " << endl;
			//if it is an int at index, then there should be no problem otherwise
			//if not, then it'll send an error '
		}else{
			//cout << "im here 3 " << endl;
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You have entered a non-int value in index" << endl;
			exit(EXIT_SUCCESS);				
		}

	}else if(dynamic_cast<Int*>(vec.at(1)) || dynamic_cast<Double*>(vec.at(1)) || dynamic_cast<Char*>(vec.at(1))){
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You inserted a non-STRING type in index 1 of GET_STR_CHAR" << endl;
			exit(EXIT_SUCCESS);
	}

	if(dynamic_cast<Char*>(vec.at(3)) || dynamic_cast<String*>(vec.at(3))){
		}else if(dynamic_cast<Int*>(vec.at(3)) || dynamic_cast<Double*>(vec.at(3))){
			//assuming everything else besides char and string 
			ofstream outputFile;
			outputFile.open(".err");
			outputFile << "You inserted a non-CHAR type in index 3 of GET_STR_CHAR" << endl;
			exit(EXIT_SUCCESS);
		}	

     }else{
		int length = (int)vec.size();
		ofstream outputFile;
		outputFile.open(".err");
		outputFile << "You have entered an invalid number of arguments for the instruction" <<endl;
		exit(EXIT_SUCCESS);
     }
}

Instruction* Char_Ops::clone(){
	return nullptr;
}

Char_Ops::~Char_Ops(){

}
