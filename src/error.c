#include <stdio.h>
#include "error.h"

void print_error(Errortype error){
    switch(error){
    case INVALID_CHARACTER :
        fprintf(stderr,"Invalid character.\n");
        break;
    case INVALID_EXPRESSION :
        fprintf(stderr,"Invalid expression.\n");
        break;
    case MISMATCHED_PARAN :
        fprintf(stderr,"Mismatched parentheses.\n");
        break;
    case MISSING_OPERAND :
        fprintf(stderr,"Missing operand.\n");
        break;
    case MISSING_OPERATOR :
        fprintf(stderr,"Missing operator.\n");
        break;
    case DIVISION_BY_ZERO :
        fprintf(stderr,"Divison by zero.\n");
        break;
    case NO_ERROR : break;    
    default :
        fprintf(stderr,"Unknown error.\n");
        break;
    }
}
