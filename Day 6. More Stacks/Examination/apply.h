/**
 * @file apply.h
 * @author Bernard Polidario
 * @details An examination on the use of pointers to functions.
 *          You have to write a generic function named `apply()` whose goal is to compute the result of another
            function when applied in turn to every element (that can be of any type) of an array. The results are
            stored in a second array.

    More precisely, the function takes 5 parameters :
        - The array containing the elements used as parameters.
        - The number of elements.
        - The size in memory of an element.
        - The function to call on each element of the array.
        - Finally, the result array containing the return values of the function calls.

    In other words, the function should look like this: 
    `void apply(void *array, int nb_elements, int size, void (*function)(void *), void *result);`

    For instance, say we have a triple function whose role is, as its name indicates, to compute the triple of
    the value passed as parameter. If we also have defined array `a` as containing integers {1,4,2,8,5,7}, then
    calling `apply(a, 6, sizeof(int), triple, b);` will result in array `b` containing {3,12,6,24,15,21}.

    We admit that the user of apply has previously created array b, which is of the same type and size as array a.
 * 
*/

#ifndef APPLY_H
#define APPLY_H
typedef int (*function)(void *, void *);

void apply(void * array, int numberOfElements, int size, function, void * result);

void triple(void * element, void * result);

void displayArray(int * array, int size);

#endif // APPLY_H