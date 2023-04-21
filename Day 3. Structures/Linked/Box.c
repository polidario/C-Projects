#include "Box.h"
#include <stdio.h>
#include <stdlib.h>

Stack * createStack(int size) {
    Stack * result = (Stack *) malloc(sizeof(Stack));
    if(!result) return 0;
    *result = 0;

    return result;
}

int isEmpty(Stack * stack) {
    // This method should return 1 if the stack is empty and 0 otherwise
    // This return can be also written as:
    // return *stack == 0;
    return !*stack;
}

int top(Stack * stack) {
    return (*stack)->value;
}

void pop(Stack * stack) {
    // Create a temporary pointer to the top of the stack
    Stack temp = *stack;

    // Move the top of the stack to the next element
    *stack = temp->next;

    // Free the memory of the previous top of the stack
    free(temp);
}

void push(Stack * stack, int value) {
    // Create a new box
    Stack temp = (Stack) malloc(sizeof(Box));
    if(!temp) return;

    * stack = temp;
    temp->value = value;
}

void destroyStack(Stack * stack) {
    // Free all the boxes in the stack
    while(*stack) {
        pop(stack);

        free(stack);
    }
}