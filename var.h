#ifndef VAR_H
#define VAR_H

#include <iostream>
#include <string>
using namespace std;

class Var //a separate parent class that holds all the setter and getter methods for the respective data types.
{
  public:
    Var();
    virtual int getInt();
    virtual double getDouble();
    virtual string getString();
    virtual void setInt(int);
    virtual void setDouble(double);
    virtual void setString(string);
    virtual void setChar(char);
    virtual char getChar();
    ~Var();
};

/*
bool isDouble(const string&);
bool isInteger(const string&);

void getEntryHelper(string); //
void getEntry(string); //
int getEntryInteger(string);
double getEntryDouble(string);
string getEntryString(string);
*/

#endif
