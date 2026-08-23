#ifndef ERROR_H
#define ERROR_H

typedef enum{
    NO_ERROR,
    INVALID_CHARACTER,
    INVALID_EXPRESSION,
    MISMATCHED_PARAN,
    MISSING_OPERAND,
    MISSING_OPERATOR,
    DIVISION_BY_ZERO
}Errortype;

void print_error(Errortype error);

#endif //ERROR_H
