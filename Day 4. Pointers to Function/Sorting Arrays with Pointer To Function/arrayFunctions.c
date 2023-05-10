#include "arrayFunctions.h"
#include <stdio.h>
#include <stdlib.h>

void sortArray(int * array, int size, comparator c) {
    // Do a Bubble sort baby!
    int left, right, temp;
    for (left = 0; left < size - 1; left++) {
        for (right = left + 1; right < size; right++) {
            if (c(array[left], array[right]) > 0) {
                temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }
    }
}

void displayArray(int * array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}