#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"
#include "error.h"

int main(){
    char exp[20];
    
    printf("C-Calculator\n");
    while(1){
        printf(">>>");
        fgets(exp,sizeof(exp),stdin);
        Result result = calculate(exp);
        if(result.Error != NO_ERROR){
            print_error(result.Error);
        }else{
            printf("%f\n",result.value);            
        }
    }
}
