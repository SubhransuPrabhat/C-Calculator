#include <stdio.h>
#include "parser.h"

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Usage: %s <expression>",argv[0]);
        return 1;
    }

    double result = parser(argv[1]);
    printf("%f",result);
    return 0;
}
