#include "set_str_char.h"
SetChar::SetChar() { //Implement the constructor later

}

void SetChar::doChar_Ops(vector<Var*>const&vec){ //do error checking for index here
    Char_Ops::checkOps(vec);
    Var *var = getEntry(vec.at(1)->getString());
    int index = vec.at(2)->getInt(); //finding the index of the char/string 
    int size = getEntry2(vec.at(1)->getString());
   

    if(dynamic_cast<Char*>(vec.at(3))){ //goes in here if it is a direct char like 'c'          
        char tempArray[size];
        char c = vec.at(3)->getChar();
        string temp = (string)(var->getString());
        //var->setString(temp);

        //For loop puts in the word into array
        for(int i=1,j=0;i<=temp.length()-2;i++,j++){
            tempArray[j] = temp.at(i);
        }

        for (int i= temp.length()-2;i<size;i++){
            tempArray[i] = ' ';
        }

        tempArray[index] = c;

        string temp2(tempArray, size-1);
        // string temp2 = new char[size];
        // std::strcpy(tempArray, temp2.c_str());
        // cout << temp2 << endl;

        //var->setString(temp2);
        Var* myString = new String(temp2);
        setEntry(vec.at(1)->getString(), myString);
        //cout << temp2 << " set" << endl;
    
        
    }else if(dynamic_cast<String*>(vec.at(3))){ //for variable ex). mychar2
        char tempArray[size]; 
        Var* tmp = getEntry(vec.at(3)->getString()); //gets the value of $mychar or the character inside it 
        //cout << tmp->getChar() << "goddam" << endl;
        string temp = (string)(var->getString());
        for(int i=0;i<temp.length();i++){
            tempArray[i] = temp.at(i);
        }

        for(int i = temp.length();i<size;i++){
            tempArray[i] = ' ';
        }

        tempArray[index] = tmp->getChar(); //replacing the selected index with $mychar 
        string temp2(tempArray, size-1);
        Var* myString = new String(temp2);
       //cout << temp2 << " set" << endl;
        setEntry(vec.at(1)->getString(), myString);

    }
}

Instruction* SetChar::clone(){
    SetChar *sc = new SetChar();
	return sc;
}


SetChar::~SetChar() { //Implement the destructor later

}
