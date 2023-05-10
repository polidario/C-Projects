/****
 * When a pointer to function is followed by a pair of parentheses, then the
 * function is called. The function is called with the arguments that are
 * specified in the parentheses.
 * 
 * For example, the following statement calls the function func() with the
 * argument 10.
 * 
 * (*func_ptr)(10);
 * 
 * The following program demonstrates the concept of pointers to function.
 * 
 * 
*/

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int (*func_ptr)(int, int);

int main() {
    func_ptr = add; // Another way is to assign the address of the function func_ptr = &add;
    printf("%d \n", (*func_ptr)(10, 20));
    return 0;
}