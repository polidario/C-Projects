#ifndef STACKSTRUCTURE_H
#define STACKSTRUCTURE_H

typedef enum {
    OK,
    ERRALLOC,
    ERROPEN,
    ERREMPTY,
    ERRNULL
} status;

char* message(status s);

typedef struct Box {
    int value;
    int * next;
} Box, * Stack;

Stack * createStack(int size);

status push(Stack * stack, int value);
status pop(Stack * stack);
status top(Stack * stack, int * result);
int isEmpty(Stack * stack);
void destroyStack(Stack * stack);

#endif
