#include "Int.h"

Int::Int(int value){ //Implement typeInt constructor here
    this->value = value;
}

int Int::getInt(){
    return value;
}

void Int::setInt(int newValue){
    value = newValue;
}

Int:: ~Int(){ //Implement typeInt destructor here
    
}
