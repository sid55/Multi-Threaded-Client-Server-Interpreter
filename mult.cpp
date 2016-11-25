#include "mult.h"

Multiply:: Multiply(){ // you guys are free to implement the constructor
    totalInt = 1;
    countInts = 0;
    countDoubles = 0;
    totalDouble = 1.0;  
}

Instruction* Multiply::clone(){
	Multiply *mult = new Multiply();
	return mult;
}

//same idea as div and add cpp files, this is to ensure if a double is needed to be produce that it will be produce.
//it counts the numbers of int and double and see which one to do.
void Multiply::doOps(vector<Var*>const&vec){
   Ops::checkOps(vec); 
    for(int i=2;i<vec.size();i++){
        if ( dynamic_cast<Int*>(vec.at(i)) ){
         totalInt = totalInt * vec.at(i)->getInt();
         countInts++;
        } else if( dynamic_cast<Double*>(vec.at(i)) ){
            totalDouble = totalDouble * vec.at(i)->getDouble();
            countDoubles++;
        } else if( dynamic_cast<String*>(vec.at(i))){
            Var *temp = getEntry(vec.at(i)->getString());
            
            if ( dynamic_cast<Int*>(temp)) {
                totalInt = totalInt * temp->getInt();
                countInts++;
            } else if( dynamic_cast<Double*>(temp)){
                totalDouble = totalDouble * temp->getDouble();
                countDoubles++;
            }
        }
    }

    int total1 = 1; //an int total
    double total2 = 1.0; //a double total
    if(countDoubles <= 0){
        total1 = totalInt;
    } else if(countDoubles > 0){
        total2 = totalDouble * (double)totalInt;
    }
//check to see which type it is and delete them based on that to ensure no memory leak.
    if(countDoubles ==0 && strcmp(typeid(total1).name(),"i") == 0){
        Var *myInt = new Int(total1);
        setEntry(vec.at(1)->getString(), myInt);
    } else if(countDoubles > 0 && strcmp(typeid(total2).name(), "d") == 0){
        Var *myDouble = new Double(total2);
        setEntry(vec.at(1)->getString(), myDouble);
    }
    
}

Multiply:: ~Multiply(){ // you guys are free to implement the destructor
    
}
