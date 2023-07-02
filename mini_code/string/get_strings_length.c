#include <stdio.h>

#define n 3

int str_len(char *str){
    int count;

    for(count=0; *(str+count) != '\0'; count++);

    return count;
}

int main(void){
    // create array of strings
    char *arr[n] = {"I love c programming", "Hello", "I am Mohamed"};

    for (int i=0; i<n; i++){
        printf( "\"%s\" length is %d\n", *(arr+i), str_len( *(arr+i) ) );
    }
}