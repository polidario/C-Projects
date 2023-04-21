#ifndef BOX_H
#define BOX_H

typedef struct Box {
    int value;
    struct Box * next;
} Box, * Stack;

Stack * createStack(int size);
int isEmpty(Stack * stack);

/***
 * For example we have a stack with the following elements:
 * 1 -> 2 -> 3 -> 4 -> 5
 * 
 * If we want to push 6, we should do the following:
 * 1. Create a new box with value 6
 * 2. Set the next of the new box to point to the top of the stack
*/
int top(Stack * stack);


void pop(Stack * stack);


void push(Stack * stack, int value);

void destroyStack(Stack * stack);

#endif