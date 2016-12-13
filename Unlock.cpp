#include "Unlock.h"

Unlock::Unlock(){

}


void Unlock::doThreadMethod(vector<Var*>&vec){

}

void Unlock::checkOps(vector<Var*>const&vec){

}

Instruction* Unlock::clone(){
    Unlock* unlock = new Unlock();
    return unlock;
}

Unlock::~Unlock(){
    
}
