#include "stackStructure.h"
#include <stdio.h>
#include <stdlib.h>

Stack * createStack(int size) {
    Stack * result = (Stack *) malloc(sizeof(Stack));
    if(!result) return 0;

    result->capacity = size;
    result->elements = (int *) malloc(size * sizeof(Stack));
    if(!result->elements) {
        free(result);
        return 0;
    }
    result->top = -1;
    return result;
}

void push(Stack * stack, int value) {
    // if(stack->top == stack->capacity - 1) {
    //     printf("Stack is full\n");
    //     return;
    // }
    stack->elements[++stack->top] = value;
}
void pop(Stack * stack) {
    stack->top--;
}
int top(Stack * stack) {
    if(stack->top == -1) {
        printf("Stack is empty\n");
        return 0;
    }

    return stack->elements[stack->top];
}
int isEmpty(Stack * stack) {
    return stack->top != -1;
}
void destroyStack(Stack * stack) {
    //if(!stack) return;
    free(stack->elements);
    free(stack);
}