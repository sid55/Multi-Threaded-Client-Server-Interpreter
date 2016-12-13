#ifndef DOUBLE_H
#define DOUBLE_H

#include <iostream>
#include "var.h"

class Double: public Var{
    private:
        double value;
    public:
        Double(double);
        double getDouble();
        void setDouble(double);
        ~Double();
};

#endif