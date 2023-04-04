/***
 * Write a "int str2int(char *str)" function that converts a string to an integer
 * Example: "123" -> 123
*/

#include <stdio.h>

int str2int(char *str) {
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        printf("The result is: %d, and the current char is: %c, current char minus 0 is: %d", result, str[i], (str[i] - '0'));
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}


int main() {
    char str[10];
    int result;

    printf("Enter a string: ");
    scanf("%s", str);

    result = str2int(str);

    printf("The result is: %d", result);

    return 0;
}