/***
 * 
 * Input and Output
 * 
 * Here are different types of Input and Output functions:
 * - printf() - prints a string to the console
 *      - %d - integer
 *      - %f - float
 *      - %lf - double
 *      - %c - char
 *      - %s - string
 *      - %p - pointer
 *      - %x - hexadecimal
 * 
 * - scanf() - reads a string from the console
 * - getchar() - reads a single character from the console
 * - putchar() - prints a single character to the console
 * 
 * Exercise:
 * Write a program that
 * - defines and initialize an array of 10 integers and this should be read from the keyboard inputs
 * - prints the array
 * - computes and prints the highest element in the array
 *      -> getMax() returns element of the array
 *
 * 
*/

#include <stdio.h>
#define ARRAY_SIZE 10

int getMax(int arr[], int size) {
    int i;
    int max = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int arr[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // for (int i = 0; i < ARRAY_SIZE; i++) {
    //     printf("%d.) %d \n", i, arr[i]);
    // }

    printf("The max element is: %d", getMax(arr, ARRAY_SIZE));

    return 0;
}