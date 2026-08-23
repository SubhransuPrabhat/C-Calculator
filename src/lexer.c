#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"
#include "calculator.h"

char isOperator(char c){
    return strchr("+-*/()^",c) != NULL;
}

int is_unary_minus(Token tokens[],int count){
    if(count==0){
        return 1;
    }
    Token prev = tokens[count-1];
    return prev.type!=TOK_NUM && prev.type!=TOK_RPARAN ;
}

int token_conversion(const char *exp,Token tokens[]){
    int i=0;
    int j=0;
    while(exp[i]!='\0' && exp[i]!='\n'){
        if(exp[i]==' '){
            i++;
            continue;
        }
        else if(isdigit(exp[i])){
            char *endptr;
            double num = strtod(exp+i,&endptr);
            i = endptr - exp;
            tokens[j++]=(Token){TOK_NUM,num};
            continue;
        }
        else if(isOperator(exp[i])){
            switch(exp[i]){
            case '+' : tokens[j++]=(Token){TOK_PLUS,0}; break;
        case '-' :
            if(is_unary_minus(tokens,j)){
                tokens[j++]=(Token){TOK_UNARY_MINUS,0};
            }
            else{
                tokens[j++]=(Token){TOK_MINUS,0};
            }
            break;
            case '*' : tokens[j++]=(Token){TOK_STAR,0}; break;
            case '/' : tokens[j++]=(Token){TOK_SLASH,0}; break;
            case '^' : tokens[j++]=(Token){TOK_POWER,0}; break;
            case '(' : tokens[j++]=(Token){TOK_LPARAN,0}; break;
            case ')' : tokens[j++]=(Token){TOK_RPARAN,0}; break;
            
        }
    }
    else{
        return -1;
    }
    i++;
}
return j;
}
