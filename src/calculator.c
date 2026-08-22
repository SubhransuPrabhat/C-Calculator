#include <stdio.h>
#include "parser.h"
#include "calculator.h"

double calculate(const char *exp){
    double result = parser(exp);
    return result;
}
