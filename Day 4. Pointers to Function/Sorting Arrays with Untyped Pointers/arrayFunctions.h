typedef int (*comparator)(int, int);

int sortArray(void * array, int size, int elementSize, int (*c)(void *, void *));
void displayArray(int * array, int size);