#include "sub.h"

Subtract:: Subtract(){ // you guys are free to implement the constructor
    totalInt = -999999;
    countInts = 0;
    countDoubles = 0;
    totalDouble = -999999.0;
}

Instruction* Subtract::clone(){
	Subtract *sub = new Subtract();
	return sub;
}

//exact same idea as div and its error checking methods. it checks for all ints, doubles, and strings and increment a counter for each respective types.
void Subtract::doOps(vector<Var*>const&vec){
    Ops::checkOps(vec);
    if(dynamic_cast<Int*>(vec.at(2))){
        totalInt = vec.at(2)->getInt();
        countInts++;
    } else if(dynamic_cast<Double*>(vec.at(2))){
        totalDouble = vec.at(2)->getDouble();
        countDoubles++;
    } else if( dynamic_cast<String*>(vec.at(2)) ){
        Var *temp = getEntry(vec.at(2)->getString());
        if(dynamic_cast<Int*>(temp)){
            totalInt = temp->getInt();
            countInts++;
        } else if(dynamic_cast<Double*>(temp)){
            totalDouble = temp->getDouble();
            countDoubles++;
        }
    }
//this is where the function or the class actually performs the subtraction methods.s
    for(int i=3;i<vec.size();i++){
        if (dynamic_cast<Int*>(vec.at(i))){
            if(totalInt!= -999999){
                 totalInt = subtractHelper(totalInt, vec.at(i)->getInt());
                 countInts++;
            } else if(totalDouble!= -999999.0){
                totalDouble = subtractHelper(totalDouble, vec.at(i)->getInt());
                countDoubles++;
            }
        } else if(dynamic_cast<Double*>(vec.at(i)) ){
            if(totalInt!=-999999){
                 totalDouble = (double)totalInt;
                 totalDouble = subtractHelper(totalDouble, vec.at(i)->getDouble());
                 countDoubles++;
            } else if(totalDouble!=-999999.0){
                //totalDouble = totalDouble / vec.at(i)->getDouble();
                totalDouble = subtractHelper(totalDouble, vec.at(i)->getDouble());
                countDoubles++;
            }
        } else if( dynamic_cast<String*>(vec.at(i))){
            Var *temp = getEntry(vec.at(i)->getString());
            if ( dynamic_cast<Int*>(temp)) { 
                if(totalInt!=-999999){
                    totalInt = subtractHelper(totalInt, temp->getInt());
                    countInts++;
                } else if(totalDouble!=-999999.0){
                    totalDouble = subtractHelper(totalDouble, temp->getInt());
                    countDoubles++;
                }
            } else if( dynamic_cast<Double*>(temp)){
                if(totalInt!=-999999){
                    totalDouble = (double)totalInt;
                    totalDouble = subtractHelper(totalDouble, temp->getDouble());
                    countDoubles++;
                } else if(totalDouble!=-999999.0){
                    totalDouble = subtractHelper(totalDouble, temp->getDouble());
                    countDoubles++;
                }
            }
        }
    }

    int total1 = 0; //an int total
    double total2 = 0.0; //a double total
    if(countDoubles <= 0){
        total1 = totalInt;
    } else if(countDoubles > 0){
        total2 = totalDouble;
    }
//deletes the cloned objects here.
    if(countDoubles == 0 && strcmp(typeid(total1).name(),"i") == 0){
        Var *myInt = new Int(total1);
        setEntry(vec.at(1)->getString(), myInt);
    } else if(countDoubles > 0 && strcmp(typeid(total2).name(), "d") == 0){
        Var *myDouble = new Double(total2);
        setEntry(vec.at(1)->getString(), myDouble);
    }
    
}

Subtract:: ~Subtract(){ // you guys are free to implement the destructor
    
}

