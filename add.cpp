#include "add.h"
#include "map.h"

Add:: Add(){ //due to auto issues, we implemented int and double separately, and if it was a double the last else statement makes the result a double instead of an int.
    totalInt = 0;
    countInts = 0;
    countDoubles = 0;
    totalDouble = 0.0;  
}

//using a common doOps through inheritance to make it user readable. 
void Add::doOps(vector<Var*>const&vec){
    Ops::checkOps(vec); //Check error works
    for(int i=2;i<vec.size();i++){ //dynamic casting allowed us to see if the this class was a child of a certain superclass
        if ( dynamic_cast<Int*>(vec.at(i)) ){
            totalInt = totalInt + vec.at(i)->getInt();
            countInts++;
        } else if( dynamic_cast<Double*>(vec.at(i)) ){
            totalDouble = totalDouble + vec.at(i)->getDouble();
            countDoubles++;
        } else if( dynamic_cast<String*>(vec.at(i))){
            string tempString = vec.at(i)->getString();
            Var *tempData = myMap.at(tempString); 
            if(dynamic_cast<Double*>(tempData)){
                totalDouble = totalDouble + tempData->getDouble();
                countDoubles++;
            } else if(dynamic_cast<Int*>(tempData)){
                totalInt = totalInt + tempData->getInt();
                countInts++;
            }
        }
    }

    int total1 = 0; //an int total
    double total2 = 0.0; //a double total
    if(countDoubles <= 0){
        total1 = totalInt;
    } else if(countDoubles > 0){
        total2 = totalDouble + (double)totalInt;
    }

    if(countDoubles ==0 && strcmp(typeid(total1).name(),"i") == 0){ //we implemented everything to vector as strings and converted them back into their respective types: int and double. 
	    Var *myInt = new Int(total1); //typeid allowed us to see if it was an int for 'i' and a double for 'd' and we process from there.
        setEntry(vec.at(1)->getString(), myInt);
    } else if(countDoubles > 0 && strcmp(typeid(total2).name(), "d") == 0){
        Var *myDouble = new Double(total2);
        setEntry(vec.at(1)->getString(), myDouble);
    }
    
}

Instruction* Add::clone(){
	Add *add = new Add();
	return add;
}

Add:: ~Add(){ // you guys are free to implement the destructor
    
}

