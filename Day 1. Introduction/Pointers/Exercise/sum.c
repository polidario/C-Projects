/**
 * Write a sum.c program that sums up all the integer
 * values from the command line arguments and prints the result
 * 
 * Output: ./sum 1 2 3 4 5
 *        15
*/

#include <stdio.h>

int str2int(char *str) {
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        //printf("The result is: %d, and the current char is: %c, current char minus 0 is: %d", result, str[i], (str[i] - '0'));
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}

int main(int argc, char *argv[]) {
    int i;
    int sum = 0;

    printf("The number of arguments is: %d\n", argc);

    for (i = 1; i < argc; i++) {
        printf("Address: %p - ARGV[%d] = %s\n", &argv[i], i, argv[i]);
        sum += str2int(argv[i]);
    }

    printf("The sum is: %d", sum);

    return 0;
}

int twoSum(int nums[], int target) {
    int i, j;
    int len = sizeof(nums) / sizeof(nums[0]);

    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (nums[i] + nums[j] == target) {
                return [i, j];
            }
        }
    }

    return [0, 0];
}