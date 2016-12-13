#include "var.h"

Var::Var(){ //Implement Var constructor here

}

Var::~Var(){ //Implement Var destructor here
    
}

int Var:: getInt(){
    return -1;
}

double Var:: getDouble() {
    return -1.0;
}

string Var:: getString() {
    return NULL;
}

void Var::setInt(int value){

}

void Var::setDouble(double value){

}

void Var::setString(string value){

}

void Var::setChar(char value){
    
}

char Var:: getChar() {
    return -1;
}

/*
bool isDouble(const string &s){
	char dot = '.';
    bool isdot = false;
    int length = (int) s.length();
    
	for(int i=0;i<length;i++){
        char temp = s.at(i);
        if(temp == dot)
            isdot = true;   
    }
    char* endptr = 0;
    strtod(s.c_str(), &endptr);
    
    if(*endptr == 0 && isdot == true)
        return true;
    else 
        return false;
}

bool isInteger(const string&s){
	char dot = '.';
    bool isdot = false;
    int length = (int) s.length();
    
	for(int i=0;i<length;i++){
        char temp = s.at(i);
        if(temp == dot)
            isdot = true;
    }

    char* endptr = 0;
    strtod(s.c_str(), &endptr);
    
    if(*endptr == 0 && isdot == false)
        return true;
	else 
    	return false;
}

int getEntryInteger(string key){
    string stringValue = mymap.at(key);
    int value = -1;
    if(isInteger(stringValue)){
        value = stoi(stringValue);
    }
    return value;
}

double getEntryDouble(string key){
    string stringValue = mymap.at(key);
    double value = -1.0;
    char*ptr;
    if(isDouble(stringValue)){
        value = stod(stringValue);
       
    }
    return value;
}

string getEntryString(string key){
    string stringValue = mymap.at(key);
    return stringValue;
}
*/




