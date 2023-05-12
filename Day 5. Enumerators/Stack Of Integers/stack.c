#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "available" improvement is not applicable here due to the fact that
// the stack is not of a fixed size

Stack * createStack(int size) {
    Stack * result = (Stack *) malloc(sizeof(Stack));

    if(!result) return 0;
    result->available = 0;

    return result;
}

status pop(Stack * stack) {
    Box * temp;                             // We create a temporary pointer
    if (!stack->head) return ERREMPTY;      // If the stack is empty, we return an error
    temp = stack->head;                     // We assign the head of the stack to the temporary pointer
    stack->head = temp;                     // We assign the next available box to the head of the stack
    temp->next = stack->available;          // We assign the next available box to the temporary pointer
    stack->available = temp;                // We assign the temporary pointer to the next available box

    return OK;
}

status push(Stack * stack, void * element) {
    Box * temp = stack->available;
    if (!temp) {
        temp = (Box *) malloc(sizeof(Box));
    } else {
        stack->available = temp->next;
    }

    if (!temp) return ERRALLOC;

    temp->value = stack->head;
    //memcpy(temp->value, element, sizeof(void *));
    memcpy(temp->value, element, stack->size);
    
    stack->head = temp;
    return OK;
}

status top(Stack * stack, void * result) {
    if (!stack->head) return ERREMPTY;
    memcpy(result, stack->head->value, stack->size);
    return OK;
}

int isEmpty(Stack * stack) {
    return stack->head == 0;
}

void destroyStack(Stack * stack) {
    Box * temp = stack->head;
    while (temp) {
        stack->head = temp->next;
        free(temp);
        temp = stack->head;
    }
    free(stack);
}

int main(int argc, char const *argv[])
{
    int size = 20;
    Stack * stack = createStack(size);

    // Check if stack is created
    if(!stack) {
        return 1;
    }

    for(int i = 0; i < size; i++) {
        printf("Pushing %d \n", i);
        push(stack, &i);
    }

    while(!isEmpty(stack)) {
        int result; // We just need an int because we are only copying int to an int
        top(stack, &result);
        printf("%d \n", result);
        pop(stack);
    }

    destroyStack(stack);

    return 0;
}
