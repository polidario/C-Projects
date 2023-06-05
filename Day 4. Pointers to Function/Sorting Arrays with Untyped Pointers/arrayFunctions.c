#include "arrayFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sortArray(void * array, int size, int elementSize, int (*c)(void *, void *)) {
    // Do a Bubble sort baby!
    void * left, * right, * temp = malloc(elementSize);
    if(!temp) return -1;

    int i;
    for (left = array; left < array + (size - 1) * elementSize; left += elementSize) {
        for (right = left + elementSize; right < array + size * elementSize; right += elementSize) {
            if (c(left, right) > 0) {
                memcpy(temp, left, elementSize);
                memcpy(left, right, elementSize);
                memcpy(right, temp, elementSize);
            }
        }
    }
    
    free(temp);

    return 0;
}

void displayArray(int * array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}