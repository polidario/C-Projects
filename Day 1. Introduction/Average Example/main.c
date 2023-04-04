/**
* @file main.c
* @brief This file contains the main function of the program
* @author bernard polidario - @polidario on GitHub
*
* To compile this file, use the following command:
* gcc -c main.c 
* gcc -c avg.c 
* gcc -o main avg.o main.o
*/

#include<stdio.h>
#include "avg.h"

int main() {
    double x = 2, y = 3;

    printf("The average of %lf and %lf is %lf)", x, y, average(x, y));
    return 0;
}