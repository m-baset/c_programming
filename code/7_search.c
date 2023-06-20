#include <stdio.h>
#define n_arr 10

int linear_search(int *ptr, int val);

void main(void){
    int arr[n_arr];
    int i;
    int val, index;

    for (i=0; i<n_arr; i++){
        printf("Enter array element %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter element you search for : ");
    scanf("%d", &val);

    index = linear_search(arr, val);

    if (index != -1){
        printf("Value %d exists at index %d", val, index);
    }
    else {
        printf("Value does not exist!");
    }

}

int linear_search(int *ptr, int val){
    int i;
    for (i=0; i<n_arr; i++){
        if (ptr[i] == val){
            return i;
        }
    }
    return -1;
}