#include <stdio.h>
#include "parser.h"
#include "calculator.h"

double calculate(const char *exp){
    return parser(exp);
}
