#include "apply.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void apply(void * array, int numOfElements, int size, function f, void * result) {
    // printf("Size of array: %d\n", numOfElements);
    // printf("Size of element: %d\n", size);
    // for (int i = 0; i < numOfElements; i++) {
    //     f(&array[i], &result[i]);
    // }

    void * end = array + numOfElements * size;
    while (array < end) {
        f(array, result);
        array += size;
        result += size;
    }
}

