#include <stdio.h>

float divide(float x, float y, char *p_zero);

void main(void){
    float x, y, result;
    char dividebyzero = 0;
    scanf("%f", &x);
    scanf("%f", &y);
    
    
    result = divide(x, y, &dividebyzero);
    if (!dividebyzero){
        printf("result : %f", result);
    }
}

float divide(float x, float y, char *p_zero){
    if (y == 0){
        printf("division by zero!");
        *p_zero = 1;
        return -1;
    }
    else{
        return x / y;
    }
}