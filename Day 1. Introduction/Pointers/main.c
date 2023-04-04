/**
 * @file main.c
 * 
 * Pointers
 * Definition: Pointer is a variable whose value is the address of another variable
 * 
 * Pointers are typed except void pointers.
 * 
 * There are two operators that are used to work with pointers:
 * - & - address of operator
 * - * - dereference operator
 * 
 * 
 * What are the main reasons to use pointers?
 * - in C, there is only a pass-by-value mechanism
 * - Array size is not known at compile time
 * - in C, there are pointers to functions
 * 
 * What is this pass-by-value mechanism?
 * - when a function is called, the arguments are passed by value
 * - the parameter of the called function is set to the value of the parameter of the calling function
*/
#include <stdio.h>
#define ARRAY_SIZE 10

void triple(int *a) {
    (*a) = (*a) * 3;
}

int main() {
    int a = 10;
    int arr[ARRAY_SIZE];

    triple(&a);

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        /* code */
        printf("%d ", &(arr[i]));
    }
    

    // printf("%d", a);

    return 0;
}