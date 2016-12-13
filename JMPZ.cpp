#include "JMPZ.h"
#include "InvalidArgument.h"
#include <fstream>
JMPZ::JMPZ(){

}

int JMPZ::checkArgs(vector<Var*>const&vec){
	JUMP::checkOps(vec);
    int temp;
    //if(isInteger(vec.at(2)) == 1){
    //  temp = isInt(vec.at(2)->getInt());
   // }
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


	if(temp == 0){
		return Label::doGet(vec);
	}else{
		return -99999;
	}
}

Instruction* JMPZ::clone(){
	JMPZ *j = new JMPZ();
	return j;
}

JMPZ::~JMPZ(){
	
}
/*
int main(){
   //Var *myInt = new Int(10);
   vector<Var*>myVec;
   //myVec.push_back(myInt);
   //cout << checkArgs(myVec) <<endl;

   myVec.push_back( new Int(3));
   myVec.push_back(new Int(2));

   Var *myString = new String("hi");
   myVec.push_back(myString);
   setEntry("hi", new Double(5.3));
   JMPZ *a; 
   cout << a->checkArgs(myVec) << endl; 

   cout << a->checkArgs(myVec) << endl;

}
*/
