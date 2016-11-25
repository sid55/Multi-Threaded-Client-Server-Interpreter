#include "Lock.h"

Lock::Lock(){

}

Lock::~Lock(){

}

void Lock::doThread(vector<Var*>const&vec){

}

void Lock::checkOps(vector<Var*>const&vec){

}

Instruction* Lock::clone(){
    Lock* lock = new Lock();
    return lock;
}