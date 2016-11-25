#include "Set.h"

Set::Set(){

}

void Set::doSet(vector<Var*>const&vec,int garbage){
    
}

int Set::doGet(vector<Var*>const&vec){
    return -1;
}


Instruction* Set::clone(){
    return nullptr;
}

void Set::checkOps(vector<Var*>const&vec){
    string myAssign = "ASSIGN";
    string myVar = "VAR"; 
    string myLabel = "LABEL"; 
    if((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myAssign))==0)){ 
        int length = (int)vec.size();
        if(length != 3){
            ofstream outputFile;
            outputFile.open(".err");
            outputFile << "You have entered an invalid number of arguments for the instruction" << endl;
            exit(EXIT_SUCCESS);
         }

        Var *tempAssign = vec.at(1);
	    Var *tempAssign2 = vec.at(2);

        Var *var1 = getEntry(tempAssign->getString());
        Var *var2;
        bool checkvar2;

        if(dynamic_cast<Int*>(tempAssign2) || dynamic_cast<Double*>(tempAssign2) || dynamic_cast<Char*>(tempAssign2)){
            checkvar2 = false;
        } else if(dynamic_cast<String*>(tempAssign2)){
            char temp = tempAssign2->getString().at(0);
            if(temp == '\"') {
                checkvar2 = false;
            } else {
                 checkvar2 = true;
                 var2 = getEntry(tempAssign2->getString());
            }
        } 
 
        bool throwError = false;
	    if(dynamic_cast<Int*>(var1)){
            if(checkvar2 == true){
                if(!dynamic_cast<Int*>(var2)){
                    throwError = true;
                }
            } else {
                if(!dynamic_cast<Int*>(tempAssign2)){
                    throwError = true;
                }
            }
	    } else if(dynamic_cast<Double*>(var1)) {
		   if(checkvar2 == true){
                if(!dynamic_cast<Double*>(var2)){
                    throwError = true;
                }
            } else {
                if(!dynamic_cast<Double*>(tempAssign2)){
                    throwError = true;
                }
            }
	    } else if(dynamic_cast<String*>(var1)) {
		    if(checkvar2 == true){
                if(!dynamic_cast<String*>(var2)){
                    throwError = true;
                }
            } else {
                if(!dynamic_cast<String*>(tempAssign2)){
                    throwError = true;
                }
            }
	    } else if(dynamic_cast<Char*>(var1)) {
		    if(checkvar2 == true){
                if(!dynamic_cast<Char*>(var2)){
                    throwError = true;
                }
            } else {
                if(!dynamic_cast<Char*>(tempAssign2)){
                    throwError = true;
                }
            }
	    }

        if(throwError == true){
		    ofstream outputFile;
		    outputFile.open(".err");
		    outputFile << "You have the wrong datatypes in Assign parameter" << endl;
		    exit(EXIT_SUCCESS);
	    }

        }
    else if((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myVar))==0)){
            int length = (int)vec.size();
            string a = "NUMERIC";
            string b = "REAL";
            string c = "CHAR";
            string d = "STRING";
            if ((vec.at(2)->getString()).compare(a) == 0) {   
                if(length != 4) {
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "The length does not meet the requirement for NUMERIC type" << endl;
                    exit(EXIT_SUCCESS);
                }
                //it is known that it has to be a numeric value
                if( dynamic_cast<Int*>(vec.at(3))) {
                }
                else { //if it does not match NUMERIC type with int type  
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "That is not a numeric value" << endl;
                    exit(EXIT_SUCCESS);
                }
            }
            else if ((vec.at(2)->getString()).compare(b) == 0) {
                if(length != 4) {
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "The length does not meet the requirement for REAL type" << endl;
                    exit(EXIT_SUCCESS);
                }

                if(dynamic_cast<Double*>(vec.at(3))){
                }
                else {
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "That is not a real value" << endl;
                    exit(EXIT_SUCCESS);
                }
            }
            else if ((vec.at(2)->getString()).compare(c) == 0) {
                if(length != 4) {
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "The length does not meet the requirement for CHAR type" << endl;
                    exit(EXIT_SUCCESS);
                }
                if(dynamic_cast<Char*>(vec.at(3))) {
                }
                else {
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "That is not a char value" << endl;
                    exit(EXIT_SUCCESS);
                }
            }
            else if ((vec.at(2)->getString()).compare(d) == 0)
            {
                if(length != 5){ //checks 
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "The length does not meet the requirement for STRING type" << endl;
                    exit(EXIT_SUCCESS);
                }

                if(dynamic_cast<Int*>(vec.at(3))){
                }else{
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "This length is not an int in the allocation for string" << endl;
                    
                    exit(EXIT_SUCCESS);
                }

                if(dynamic_cast<String*>(vec.at(4))){
                    
                }
                else {
                    ofstream outputFile;
                    outputFile.open(".err");
                    outputFile << "that is not a char array value" << endl;
                    exit(EXIT_SUCCESS);                    
                }
            }
            else {
                ofstream outputFile;
                outputFile.open(".err");
                outputFile << "You have not entered a correct data type" << endl;
                exit(EXIT_SUCCESS);
            }
    }
    else if((dynamic_cast<String*>(vec.at(0))) && ((vec.at(0)->getString().compare(myLabel))==0)){
            int length = (int)vec.size();
            if(length != 2){
                ofstream outputFile;
                outputFile.open(".err");
                outputFile << "You have entered an invalid number of arguments for the instruction." << endl;
                exit(EXIT_SUCCESS);
            }
        }
    else { 
            int length = (int)vec.size();
            ofstream outputFile; 
            outputFile.open("err");
            outputFile << "You have entered an invalid instruction name" << endl;
            exit(EXIT_SUCCESS);
    }
}

Set::~Set(){

}
