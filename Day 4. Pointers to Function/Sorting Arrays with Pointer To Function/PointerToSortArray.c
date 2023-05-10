#include <stdio.h>
#include "arrayFunctions.h"

int ascending(int a, int b) {
    return a - b;
}

int descending(int a, int b) {
    return b - a;
}

int main() {
    int array[10] = {13, 2, 36, 4, 2, 6, 7, 99, 9, 17};
    int i, j;
    
    sortArray(array, 10, descending);
    displayArray(array, 10);
    return 0;
}