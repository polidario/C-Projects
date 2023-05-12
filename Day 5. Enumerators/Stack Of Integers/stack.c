#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

static Stack available = 0;

Stack * createStack(int size) {
    Stack * result = (Stack *) malloc(sizeof(Stack));

    if(!result) return 0;
    *result = 0;

    return result;
}

status push(Stack * stack, void * value) {
    Stack temp = available;

    if(!temp) {
        temp = (Stack) malloc(sizeof(Box));
    }

    if(!temp) return ERRALLOC;

    if(available) available = available->next;

    temp->value = value;

    temp->next = *stack;

    *stack = temp;

    return OK;
}

status top(Stack * stack, void * result) {
    if(!*stack) return ERREMPTY;

    *(void **) result = (*stack)->value;

    return OK;
}

status pop(Stack * stack) {
    if(!*stack) return ERREMPTY;

    Stack temp = *stack;

    *stack = temp->next;

    temp->next = available;

    available = temp;

    return OK;
}

int main(int argc, char const *argv[])
{
    /* Define 2 integers (value 1 and 2) and a Stack
        push the int on top of the stack
        while stack is not empty
            print top most element
            pop the stack

        Check the return value of the functions
      */

    int value1 = 1;
    int value2 = 2;
    Stack * stack = 0;

    stack = createStack(2);

    if(!stack) {
        printf("Allocation error\n");
        return 1;
    }

    if(push(stack, &value1)) {
        printf("Push error\n");
        return 1;
    }

    if(push(stack, &value2)) {
        printf("Push error\n");
        return 1;
    }

    void * result = 0;

    while(!isEmpty(stack)) {
        if(top(stack, &result)) {
            printf("Top error\n");
            return 1;
        }

        printf("%d\n", *(int *) result);

        if(pop(stack)) {
            printf("Pop error\n");
            return 1;
        }
    }

    destroyStack(stack);

    return 0;
}
