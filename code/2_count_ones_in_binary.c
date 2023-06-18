#include <stdio.h>

int count_ones_1(int number);
int count_ones_2(int number);

int main(void){
    int number;

    printf("Enter Your Number : ");
    scanf("%d", &number);

    printf("Number of ones : %d\n", count_ones_2(number));

    return 0;
}

int count_ones_1(int number){
    char count = 0;
    while(number){
        if (number & 1){
            count++;
        }
        number = number >> 1;
    }

    return count;
}

int count_ones_2(int number){
    char count = 0;

    while(number){
        number = number & (number - 1);
        count++;
    }

    return count;
}