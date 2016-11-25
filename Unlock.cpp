#include "Unlock.h"

Unlock::Unlock(){

}


void Unlock::doThread(vector<Var*>const&vec){

}

void Unlock::checkOps(vector<Var*>const&vec){

}

Instruction* Unlock::clone(){
    Unlock* unlock = new Unlock();
    return unlock;
}

Unlock::~Unlock(){
    
}