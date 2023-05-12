#include "stackStructure.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

status top (Stack * stack, int * result) {
    if(!*stack) return ERREMPTY;

    *result = (*stack)->value;
    return OK;
}

status push(Stack * stack, int value) {
    Box * newBox = (Box *) malloc(sizeof(Box));
    if(!newBox) return ERRALLOC;

    newBox->value = value;
    newBox->next = *stack;
    *stack = newBox;
    return OK;
}

status pop(Stack * stack) {
    if(!*stack) return;

    Box * temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}


int isEmpty(Stack * stack) {
    return !*stack;
}

void destroyStack(Stack * stack) {
    while(*stack) {
        Box * temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

Stack * createStack(int size) {
    Stack * result = (Stack *) malloc(sizeof(Stack));
    if(!result) return 0;

    return result;
}

char * message(status s) {
    switch(s) {
        case OK: return "OK";
        case ERRALLOC: return "Allocation error";
        case ERROPEN: return "File opening error";
        case ERREMPTY: return "Stack is empty";
        case ERRNULL: return "Null pointer";
        default: return "Unknown error";
    }
}