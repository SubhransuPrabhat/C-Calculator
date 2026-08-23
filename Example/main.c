#include <stdio.h>
#include <calculator.h>

int main(int argc,char *argv[]){
    if(argc!=2){
        printf("Usage: %s <expression>",argv[0]);
        return 1;
    }
    
    Result result = calculate(argv[1]);

    if(result.Error != NO_ERROR){
        print_error(result.Error);
        return 1;
    }
    
    printf("%f",result.value);
}
