#include "assign.h"
#include "map.h"
#include <fstream>

Assign::Assign(){

}

void Assign::doSet(vector<Var*>const&vec, int extra){
	Set::checkOps(vec);
	
	Var *tempAssign = vec.at(1);
	Var *tempAssign2 = vec.at(2);

    Var *var1 = getEntry(tempAssign->getString());
    Var *var2;
    bool checkvar2;

    if(dynamic_cast<Int*>(tempAssign2) 
		|| dynamic_cast<Double*>(tempAssign2) 
			|| dynamic_cast<Char*>(tempAssign2)){
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

	if(dynamic_cast<Int*>(var1)){
		if(checkvar2 == true){
			var2 = getEntry(tempAssign2->getString());
			var1->setInt(var2->getInt());
		} else {
			var1->setInt(tempAssign2->getInt());
		}
	} else if(dynamic_cast<Double*>(var1)){
		if(checkvar2 == true){
			var2 = getEntry(tempAssign2->getString());
			var1->setDouble(var2->getDouble());
		} else {
			var1->setDouble(tempAssign2->getDouble());
		}
	} else if(dynamic_cast<String*>(var1)){
		if(checkvar2 == true){
			var2 = getEntry(tempAssign2->getString());
			var1->setString(var2->getString());
		} else {
			var1->setString(tempAssign2->getString());
		}
	} else if(dynamic_cast<Char*>(var1)){
		if(checkvar2 == true){
			var2 = getEntry(tempAssign2->getString());
			var1->setChar(var2->getChar());
		} else {
			var1->setChar(tempAssign2->getChar());
		}
	}
}

Instruction* Assign::clone(){
	Assign *assign = new Assign();
	return assign;
}

Assign::~Assign(){

}

