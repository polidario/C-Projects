#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef struct Box {
    char * value[1];
    struct Box * next;
} Box;

typedef struct {
    Box * head;
    int size;
} Stack;

Stack * createStack(int size);

status push(Stack * stack, void * value);
status pop(Stack * stack);
status top(Stack * stack, void * result);
int isEmpty(Stack * stack);
void destroyStack(Stack * stack);
#endif