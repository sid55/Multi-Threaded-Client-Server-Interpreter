#include "String.h"


String::String(string value){ //Implement typeInt constructor here
    this->value = value;
}

string String::getString(){
    return value;
}

void String::setString(string newValue){
    value = newValue;
}

String::~String(){ //Implement typeInt destructor here
    
}
