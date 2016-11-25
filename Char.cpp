#include "Char.h"


Char::Char(char value){ //Implement typeInt constructor here
    this->value = value;
}

char Char::getChar(){
    return value;
}

void Char::setChar(char newValue){
    value = newValue;
}

Char::~Char(){ //Implement typeInt destructor here
    
}
