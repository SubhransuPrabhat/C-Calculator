#include <math.h>
#include <stdlib.h>
#include "parser.h"
#include "lexer.h"
#include "error.h"
#define MAX 50

typedef struct{
    double data[MAX];
    int top;
}NumStack;

typedef struct{
    Tokentype data[MAX];
    int top;
}OpStack;

typedef enum{
    EXPECT_OPERAND,
    EXPECT_OPERATOR
}ParserState;

//Operand stack
void init_num_stack(NumStack *s){s->top=-1;}
void push_num(NumStack *s,double val){s->data[++s->top]=val;}
double pop_num(NumStack *s){return s->data[s->top--];}
double peek_num(NumStack *s){return s->data[s->top];}

//Operator stack
void init_op_stack(OpStack *s){s->top=-1;}
void push_op(OpStack *s,Tokentype op){s->data[++s->top]=op;}
Tokentype pop_op(OpStack *s){return s->data[s->top--];}
Tokentype peek_op(OpStack *s){return s->data[s->top];}

int precedence(Tokentype op){
    switch(op){
    case TOK_PLUS :
    case TOK_MINUS : return 1;
    case TOK_STAR :
    case TOK_SLASH :return 2;
    case TOK_POWER :return 3;
    case TOK_UNARY_MINUS :return 4;
    default : return 0;
    }
}

double apply_op(double a,double b,Tokentype op){
    switch(op){
    case TOK_PLUS : return a+b;
    case TOK_MINUS : return a-b;
    case TOK_STAR : return a*b;
    case TOK_SLASH : return a/b;
    case TOK_POWER : return pow(a,b);
    default : return 0;
    }
}


Result parser(const char *exp){
    Token tokens[MAX];
    int token_count=token_conversion(exp,tokens);

    if(token_count<0){
        return (Result){0,INVALID_CHARACTER};
    }

    NumStack num_stack; init_num_stack(&num_stack);
    OpStack op_stack; init_op_stack(&op_stack);

    ParserState next = EXPECT_OPERAND;
    
    for(int i=0;i<token_count;i++){
        Token t = tokens[i];

        switch(t.type){
        case TOK_NUM:
            if(next == EXPECT_OPERATOR){
                return (Result){0,MISSING_OPERAND};
            }
            push_num(&num_stack,t.value);
            next = EXPECT_OPERATOR;
            break;
        case TOK_LPARAN:
            push_op(&op_stack,t.type);
            break;
        case TOK_RPARAN:
            while(op_stack.top!=-1 && peek_op(&op_stack)!=TOK_LPARAN){
                Tokentype op = pop_op(&op_stack);
                if(op==TOK_UNARY_MINUS){
                    double a = pop_num(&num_stack);
                    push_num(&num_stack,-a);
                }else{
                    double num2 = pop_num(&num_stack);
                    double num1 = pop_num(&num_stack);
                    if(op==TOK_SLASH && num2==0){
                        return (Result){0,DIVISION_BY_ZERO};
                    }
                    push_num(&num_stack,apply_op(num1,num2,op));
                }
            }
            if(op_stack.top==-1){
                return (Result){0,MISMATCHED_PARAN};
            }
            pop_op(&op_stack);
            break;
        case TOK_PLUS :
        case TOK_MINUS :
        case TOK_UNARY_MINUS :
        case TOK_STAR :
        case TOK_SLASH :
        case TOK_POWER :
            if(next == EXPECT_OPERAND && t.type!=TOK_UNARY_MINUS){
                return (Result){0,MISSING_OPERAND};
            }
            while(op_stack.top!=-1 && peek_op(&op_stack)!=TOK_LPARAN){
                int top_prec = precedence(peek_op(&op_stack));
                int curr_prec = precedence(t.type);

                if(top_prec >= curr_prec && t.type != TOK_POWER){
                    Tokentype op = pop_op(&op_stack);
                    if(op==TOK_UNARY_MINUS){
                        double a = pop_num(&num_stack);
                        push_num(&num_stack,-a);
                    }else{
                        double num2 = pop_num(&num_stack);
                        double num1 = pop_num(&num_stack);
                        if(op==TOK_SLASH && num2==0){
                            return (Result){0,DIVISION_BY_ZERO};
                        }
                        push_num(&num_stack,apply_op(num1,num2,op));
                    }
                }
                else{
                    break;
                }
            }
            push_op(&op_stack,t.type);
            next = EXPECT_OPERAND;
             break;
        }
    }
    while(op_stack.top!=-1){
        Tokentype op = pop_op(&op_stack);
        if(op==TOK_LPARAN){
            return (Result){0,MISMATCHED_PARAN};
        }
        if(op==TOK_UNARY_MINUS){
            double a = pop_num(&num_stack);
            push_num(&num_stack,-a);
        }else{
            double num2 = pop_num(&num_stack);
            double num1 = pop_num(&num_stack);
            if(op==TOK_SLASH && num2==0){
                return (Result){0,DIVISION_BY_ZERO};
            }
            push_num(&num_stack,apply_op(num1,num2,op));
        }
    }
    return (Result){pop_num(&num_stack),NO_ERROR};
}
