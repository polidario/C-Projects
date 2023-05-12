#include "apply.h"

#include <stdlib.h>
#include <stdio.h>

void triple(void * pointer_in, void * pointer_out) {
    *(int *) pointer_out = 3 * (*(int *) pointer_in);
    //* pointer_out = 3 * (* pointer_in);
}

void displayArray(int * array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int a[] = {1,4,2,8,5,7};
    int b[6];

    apply(a, 6, sizeof(int), (function) triple, b);
    
    printf("\nBEFORE: \n");
    displayArray(a, 6);

    printf("\n");

    printf("\nAFTER: \n");
    displayArray(b, 6);

    return 0;
}