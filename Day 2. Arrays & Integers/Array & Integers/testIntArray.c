/***
 * The goal of this exercise is to create an array of integers
 * and use the functions defined in the IntArray header file to:
 *  - Display the array (All must be zeroed first)
 *  - Populate the array with user input
 *  - Display the array once again
 *  - Sort the array
 *  - Display the sorted array
 *  - Destroy the array to free the memory
 *  - And lastly, check if the array is destroyed
 * 
 * ***/
#include <stdio.h>
#include "IntArray.h"

int main() {
    int size, * array;
    printf("\nPlease enter the size of the Array: ");
    scanf("%d", &size);

    array = createRandomArray(size);
    if(!array) {
        return 1;
    }
    displayArray(array, size);

    // for(int i = 0; i < size; i++) {
    //     printf("\nEnter element %d: ", i);
    //     scanf("%d", &array[i]);
    // }

    // displayArray(array, size);

    sortArray(array, size);

    displayArray(array, size);

    destroyArray(&array, size);

    if(array) { printf("\nNon-null pointer\n"); }

    return 0;

}