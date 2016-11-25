#include "sleep.h"

Sleep::Sleep(){

}

void Sleep::doMisc(vector<Var*>const&vec){ //it makes the program suspend for getInt() or getString() amount of seconds.
    Misc::checkOps(vec);
    int sleep = -1;
    if(dynamic_cast<Int*>(vec.at(1))){
        sleep = vec.at(1)->getInt();
    } else if(dynamic_cast<String*>(vec.at(1))){
        Var *temp = getEntry(vec.at(1)->getString());
        sleep = vec.at(1)->getInt();
    }

    for(int i = sleep; i>0; i--){
        std::this_thread::sleep_for(std::chrono::seconds(1)); //this initializes the sleep mode for the program
    }
}

Instruction* Sleep::clone(){
    Sleep *s = new Sleep();
	return s;
}

Sleep::~Sleep(){

}
