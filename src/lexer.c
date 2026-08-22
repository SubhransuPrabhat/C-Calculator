#include <ctype.h>
#include <string.h>
#include "lexer.h"

char isOperator(char c){
    return strchr("+-*/()^",c) != NULL;
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
            int num=0;
            while(isdigit(exp[i])){
                int temp=exp[i++] - '0';
                num=num*10+temp;                
            }
            tokens[j++]=(Token){TOK_NUM,num};
            continue;
        }
        if(isOperator(exp[i])){
            switch(exp[i]){
            case '+' : tokens[j++]=(Token){TOK_PLUS}; break;
            case '-' : tokens[j++]=(Token){TOK_MINUS}; break;
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
