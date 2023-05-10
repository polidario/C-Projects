typedef int (*comparator)(int, int);

void sortArray(int * array, int size, comparator compare);
void displayArray(int * array, int size);