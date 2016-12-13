#ifndef CHECKTOKEN_H
#define CHECKTOKEN_H

#include <vector>
#include <iostream>
#include <string.h>
#include "var.h"
using namespace std; //checking to see if the individual lines of the input file is their respective types. 
//if it is, then it would return true and false if not.

extern string globalString;
extern int stringCount;

bool isDouble(const string&);
bool isInteger(const string&);
bool isChar(const string&);
bool isString(const string&);
vector<Var*> handleStringsMain(vector<Var*>&,string); 
/*
void getEntryHelper(string); //
void getEntry(string); //
int getEntryInteger(string);
double getEntryDouble(string);
string getEntryString(string);
*/



#endif
