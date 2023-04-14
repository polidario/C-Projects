#ifndef STACKSTRUCTURE_H
#define STACKSTRUCTURE_H

typedef struct {
    /* data */
    int capacity;
    int * elements;
    int top;
} Stack;

Stack * createStack(int size);
void push(Stack * stack, int value);
void pop(Stack * stack);
int top(Stack * stack);
int isEmpty(Stack * stack);
void destroyStack(Stack * stack);

#endif