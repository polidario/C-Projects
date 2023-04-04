/***
 * 
 * Pre-processor
 * 
 * 1. #include
 * 2. #define
 * 3. #undef
 * 4. #ifdef
 * 5. #ifndef  ... #endif
 * 
*/

// Example of #ifndef
// #ifndef MY_HEADER_FILE
// #define MY_HEADER_FILE
//
// #endif
#ifndef MY_HEADER_FILE
#define MY_HEADER_FILE
typedef struct {
    int day;
    char month[10];
    int year;
} Date;
#endif

int main() {
    Date today;
    today.day = 1;
    strcpy(today.month, "January");
    today.year = 2021;

    return 0;
}