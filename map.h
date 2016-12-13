#ifndef MAP_H
#define MAP_H

#include "var.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;
//creates a global map for all of the classes and methods to use. 
//this just sets and gets the entries depending on the arguments of the operation and statements.
extern map<string, Var*> myMap;
extern map<string, int> myMap2;
extern map<string, int> sizeMap;

//for variables
void setEntry(string, Var*);
Var *getEntry(string);

//for labels
void setEntryMap2(string, int);
int getEntryMap2(string);

//for size
void setEntry2(string, int);
int getEntry2(string);


#endif
