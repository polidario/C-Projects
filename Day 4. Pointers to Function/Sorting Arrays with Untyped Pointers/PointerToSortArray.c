#include <stdio.h>
#include "arrayFunctions.h"

int ascending(void * pointer1, void * pointer2) {
    return *(int *)pointer1 - *(int *)pointer2;
}

int descending(void * pointer1, void * pointer2) {
    return *(int *)pointer2 - *(int *)pointer1;
}

int main() {
    int array[10] = {13, 2, 36, 4, 2, 6, 7, 99, 9, 17};
    int i, j;
    
    sortArray(array, 10, descending);
    displayArray(array, 10);
    return 0;
}