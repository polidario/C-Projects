#include <stdio.h>
#include "stackStructure.h"

int main() {
    int size = 10;
    Stack * stack = createStack(size);

    // Check if stack is created
    if(!stack) {
        return 1;
    }

    for(int i = 0; i < size; i++) {
        push(stack, i);
    }

    while(isEmpty(stack)) {
        printf("%d \n", top(stack));
        pop(stack);
    }

    destroyStack(stack);

    return 0;

}