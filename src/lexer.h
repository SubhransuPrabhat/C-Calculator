#ifndef LEXER_H
#define LEXER_H

typedef enum{
    TOK_NUM,
    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,
    TOK_POWER,
    TOK_LPARAN,
    TOK_RPARAN,
    TOK_UNARY_MINUS
} Tokentype;

typedef struct{
    Tokentype type;
    double value;
}Token;

int token_conversion(const char *exp,Token tokens[]);

#endif //LEXER_H
