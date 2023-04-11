int * createArray(int size);
int * createRandomArray(int size);

/**
 * For security reasons, it's best to zeroed all of the elements in the array
 * before destroying it. This is to prevent any sensitive data from being
 * leaked.
 * 
*/
void destroyArray(int ** array, int size);
void displayArray(int * array, int size);
void sortArray(int * array, int size);