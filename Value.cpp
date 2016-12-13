#include "Value.h"

Value::Value() {}

void Value::doSet(vector<Var *> const &vec,int garbage)
{
    Set::checkOps(vec);
    string a = "NUMERIC";
    string b = "REAL";
    string c = "CHAR";
    string d = "STRING";

    if ((vec.at(2)->getString()).compare(a) == 0) {
        Var *num = new Int(vec.at(3)->getInt());
        setEntry(vec.at(1)->getString(), num);
    }
    else if ((vec.at(2)->getString()).compare(b) == 0) {
        Var *real = vec.at(3);
        setEntry(vec.at(1)->getString(), real);
    }
    else if ((vec.at(2)->getString()).compare(c) == 0) {
        Var *cha = new Char(vec.at(3)->getChar());
        setEntry(vec.at(1)->getString(), cha);
    }
    else if ((vec.at(2)->getString()).compare(d) == 0) {
        Var *str = vec.at(4);
        Var *tempSize = vec.at(3);
        int size = tempSize->getInt();
        setEntry(vec.at(1)->getString(), str);
        setEntry2(vec.at(1)->getString(), size);
    }
}

Instruction* Value::clone(){
	Value *val = new Value();
	return val;
}

Value::~Value() {}
