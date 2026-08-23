#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "error.h"

typedef struct{
    double value;
    Errortype Error;
}Result;

Result calculate(const char *exp);

#endif //CALCULATOR_H
