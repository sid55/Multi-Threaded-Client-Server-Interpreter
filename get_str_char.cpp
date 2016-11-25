#include "get_str_char.h"

GetChar::GetChar(){ //Implement constructor here

}
//same as add.cpp implementation, but it changes the selected index of a char into another of the their parameter.
void GetChar::doChar_Ops(vector<Var*>const&vec){ //do error checking for index here
    //cout << "hi, in get" << endl;
    Char_Ops::checkOps(vec);
    Var* temp = getEntry(vec.at(1)->getString());
    //cout << temp->getString() << "this is the string im looking at" << endl;
    int index = vec.at(2)->getInt();
    //cout << index << " this is the index" << endl;
    string tmp = (string)(temp->getString());
    //cout << tmp << " this is temp3 here" << endl;
    char c = tmp.at(index);
    //cout << c << " this is the character im using" << endl;
    Var* holder = new Char(c);
    setEntry(vec.at(3)->getString(), holder);
    //cout << holder->getChar() << " this is the new $mychar1" << endl;
    //cout << "Hi" << endl;
    //temp2->setChar(c)    
    //cout << hold->getChar() << " this is a char" << endl;
    //setEntry(vec.at(3)->getString(), hold);
}

Instruction* GetChar::clone(){
	GetChar *gc = new GetChar();
	return gc;
}

GetChar::~GetChar(){ //Implement destructor here

}
