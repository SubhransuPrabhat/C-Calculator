#include <stdio.h>
#include "error.h"

void print_error(Errortype error){
    switch(error){
    case INVALID_CHARACTER :
        fprintf(stderr,"ERROR: Invalid character.\n");
        break;
    case INVALID_EXPRESSION :
        fprintf(stderr,"ERROR: Invalid expression.\n");
        break;
    case MISMATCHED_PARAN :
        fprintf(stderr,"ERROR: Mismatched parentheses.\n");
        break;
    case MISSING_OPERAND :
        fprintf(stderr,"ERROR: Missing operand.\n");
        break;
    case MISSING_OPERATOR :
        fprintf(stderr,"ERROR: Missing operator.\n");
        break;
    case DIVISION_BY_ZERO :
        fprintf(stderr,"ERROR: Divison by zero.\n");
        break;
    case NO_ERROR : break;    
    default :
        fprintf(stderr,"ERROR: Unknown error.\n");
        break;
    }
}
