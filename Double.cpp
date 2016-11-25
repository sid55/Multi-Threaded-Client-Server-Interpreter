#include "Double.h"


Double::Double(double value){ //Implement Double constructor here
    this->value = value;
}

double Double::getDouble(){
    return value;
}

void Double::setDouble(double newValue){
    value = newValue;
}

Double::~Double(){ //Implement Double destructor here
    
}
