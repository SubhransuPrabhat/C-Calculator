#include <stdio.h>
#include "parser.h"
#define MAX 50

int main(void){
    char exp[MAX];

    printf("Enter expression:");
    fgets(exp,MAX,stdin);

    double result = parser(exp);
    printf("Result:%f",result);
    return 0;
}
