#include "label.h"

int counter = 0;

Label::Label(){

}

void Label::doSet(vector<Var*>const& vec,int x){
	Set::checkOps(vec);
	counter = x;
	string lab = vec.at(1)->getString();
	setEntryMap2(lab, counter);
}

int Label::doGet(vector<Var*>const& vec){
	string lab = vec.at(1)->getString();
	return getEntryMap2(lab);
}


int Label::getCounter(){
    return counter;
}

void Label::setCounter(int count){
   counter = count;
}

void Label::increaseCounter(){
    counter = counter + 1;
}

Instruction* Label::clone(){
	Label *label = new Label();
	return label;
}


Label::~Label(){

}
