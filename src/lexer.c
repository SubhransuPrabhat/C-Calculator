#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

char isOperator(char c){
    return strchr("+-*/()^",c) != NULL;
}

int is_unary_minus(Token tokens[],int count){
    if(count==0){
        return 1;
    }
    Token prev = tokens[count-1];
    return prev.type!=TOK_NUM && prev.type!=TOK_LPARAN ;
}

int token_conversion(const char *exp,Token tokens[]){
    int i=0;
    int j=0;
    while(exp[i]!='\0' && exp[i]!='\n'){
        if(exp[i]==' '){
            i++;
            continue;
        }
        if(isdigit(exp[i])){
            char *endptr;
            double num = strtod(exp+i,&endptr);
            i += (endptr-(exp+i));
            tokens[j++]=(Token){TOK_NUM,num};
            continue;
        }
        if(isOperator(exp[i])){
            switch(exp[i]){
            case '+' : tokens[j++]=(Token){TOK_PLUS}; break;
            case '-' :
                if(is_unary_minus(tokens,j)){
                    tokens[j++]=(Token){TOK_UNARY_MINUS};
                }
                else{
                    tokens[j++]=(Token){TOK_MINUS};
                }
                break;
            case '*' : tokens[j++]=(Token){TOK_STAR}; break;
            case '/' : tokens[j++]=(Token){TOK_SLASH}; break;
            case '^' : tokens[j++]=(Token){TOK_POWER}; break;
            case '(' : tokens[j++]=(Token){TOK_LPARAN}; break;
            case ')' : tokens[j++]=(Token){TOK_RPARAN}; break;
            }
        }
        i++;
    }
    return j;
}
