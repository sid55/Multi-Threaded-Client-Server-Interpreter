#include "Barrier.h"

Barrier::Barrier(){

}

Barrier::~Barrier(){

}

void Barrier::doThread(vector<Var*>const&vec){

}

void Barrier::checkOps(vector<Var*>const&vec){

}

Instruction* Barrier::clone(){
    Barrier *barrier = new Barrier();
    return barrier;
}