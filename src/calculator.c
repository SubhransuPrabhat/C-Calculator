#include <stdio.h>
#include "parser.h"
#include "calculator.h"

Result calculate(const char *exp){
    return parser(exp);
}
