#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"
#include "error.h"

int main(){
    char exp[20];
    
    printf("C-Calculator\n");
    while(1){
        printf(">>>");
        fgets(exp,sizeof(exp),stdin);
        if(strcmp(exp,"exit\n") == 0)
          exit(0);
        Result result = calculate(exp);
        if(result.Error != NO_ERROR){
            print_error(result.Error);
        }else{
            printf("%f\n",result.value);            
        }
    }
    return 0;
}
