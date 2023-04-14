#include <stdio.h>
#include <stdlib.h>
#include "IntArray.h"

int * createArray(int size) {
    int * array = (int *) malloc(size * sizeof(int));
    if(!array) return 0;
    for(int i = 0; i < size; i++) {
        array[i] = 0;
    }
    return array;
}

int * createRandomArray(int size) {

    int * array = (int *) malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {
        array[i] = rand() % (size * 2);
    }

    return array;
}

void destroyArray(int ** array, int size) {
    if(!array) return;
    for(int i = 0; i < size; i++) {
        (*array)[i] = 0;
    }
    free(*array);
    *array = 0;
}

void sortArray(int * array, int size) {
    if(!array) return;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void displayArray(int * array, int size) {
    if (size > MAXDISPLAY) {
        printf("\nArray size is too large. Max size is %d\n", MAXDISPLAY);
        return;
    }

    if(!array) return;
    printf("\n[ ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("]\n");
}