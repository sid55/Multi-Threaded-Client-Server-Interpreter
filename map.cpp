#include "map.h"
#include "datatypes.h"
#include <fstream>

map<string, Var*> myMap; //variable map
map<string, int> myMap2; //label map
map<string, int> sizeMap; 

void setEntry(string key, Var* value){
    if(myMap.find(key) == myMap.end()){ //cannot find key
         myMap.insert(make_pair(key, value));
    } else { //myMap.find(key) != myMap.end()
        Var *varTemp = myMap.at(key);
        if(dynamic_cast<Int*>(varTemp) && dynamic_cast<Int*>(value)){
            varTemp->setInt(value->getInt());
        } else if(dynamic_cast<Double*>(varTemp) && dynamic_cast<Double*>(value)){
            varTemp->setDouble(value->getDouble());
        } else if(dynamic_cast<String*>(varTemp)){
            varTemp->setString(value->getString());
        } else if(dynamic_cast<Char*>(varTemp)){
            varTemp->setChar(value->getChar());
        }
    }
}

Var *getEntry(string key){
    if ( myMap.find(key) == myMap.end()) { //cannot find key
        ofstream outputFile;
		outputFile.open(".err");
		outputFile << "The key for the entry you are looking for cannot be found" <<endl;
		exit(EXIT_SUCCESS);
    } else { //myMap.find(key) != myMap.end()
        Var *varTemp = myMap.at(key);
	    return varTemp;
    }
}

void setEntryMap2(string key, int value){
    myMap2.insert(make_pair(key, value));
}

int getEntryMap2(string key){
    if(myMap2.find(key) == myMap2.end()){ //cannot find key
	ofstream outputFile;
	outputFile.open(".err");
	outputFile << "The label you are looking for does not exist" <<endl;
	exit(EXIT_SUCCESS);
    } else { 
        return myMap2.at(key);
    }
}

//this is for the memory allocation for each string variable
void setEntry2(string key, int value){
   sizeMap.insert(make_pair(key, value));
}

int getEntry2(string key){
    if ( sizeMap.find(key) == sizeMap.end()) { //cannot find key
        ofstream outputFile;
		outputFile.open(".err");
		outputFile << "The key for the entry you are looking for cannot be found" <<endl;
		exit(EXIT_SUCCESS);
    } else { //myMap.find(key) != myMap.end()
        int size = sizeMap.at(key);
	    return size;
    }
}