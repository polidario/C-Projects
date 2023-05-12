#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack * createStack(int capacity) {
    Stack * stack = (Stack *) malloc(sizeof(Stack));
    if (!stack) {
        return 0;
    }

    stack->size = capacity;
    stack->head = 0;
    return stack;
}

int isEmpty(Stack * stack) {
    return stack->head == 0;
}

status pop(Stack * stack) {
    if (isEmpty(stack)) {
        return 1;
    }

    Box * temp = stack->head; // Store the head in a temporary variable
    stack->head = stack->head->next; // Move the head to the next element
    free(temp); // Free the memory of the previous head
    return 0;
}

status push(Stack * stack, void * value) {
    Box * temp = (Box *) malloc(sizeof(Box) + stack->size - 1);
    // The reason why we are adding the stack->size - 1 is because we are
    // allocating 1 byte for the value. We need to allocate the size of the
    // value. Minus 1 because we already allocated 1 byte.

    if (!temp) {
        return ERRALLOC;
    }
    temp->next = stack->head; // Make the new box point to the previous head
    stack->head = temp; // Make the head point to the new box
    memcpy(temp->value, value, stack->size); // Copy the value to the new box
    return OK;
}

status top(Stack * stack, void * result) {
    if(isEmpty(stack)) {
        return ERREMPTY;
    }

    memcpy(result, stack->head->value, stack->size);
    return OK;
}

void destroyStack(Stack * stack) {
    while (!isEmpty(stack)) {
       Box * temp = stack->head;
       stack->head = temp;
       free(temp);
    }
    free(stack);
}

int main(int argc, char const *argv[])
{
    /* code */
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
