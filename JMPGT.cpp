#include "JMPGT.h"
#include "InvalidArgument.h"

JMPGT::JMPGT(){

}

int JMPGT::checkArgs(vector<Var*> const&vec){
    JUMP::checkOps(vec);
	int temp;
    int temptemp;
    //error checking on the jmpgt arguments 
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

//the initialization of temptemp here to compare against temp on whether or not jmpgt should go.
    if (dynamic_cast<Int*>(vec.at(3))){
         temptemp = vec.at(3)->getInt();
    }else if (dynamic_cast<String*>(vec.at(3))){
         Var* temp3 = getEntry(vec.at(3)->getString());
	 if (dynamic_cast<Int*>(temp3)){
		temptemp = temp3->getInt();
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

	if(temp > temptemp){
		return Label::doGet(vec);
	}else{
		return -99999;
	}
}

Instruction* JMPGT::clone(){
	JMPGT *j = new JMPGT();
	return j;
}

JMPGT::~JMPGT(){
	
}

