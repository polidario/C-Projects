/***
 * 
 * 1. Predefined Types
 *  - int
 *  - float
 *  - double
 *  - char
 *  - void
 *  - bool -> Numbers are also boolean in C
 *      For example: 1 is true, 0 is false
 *                   negative integers are true
 *                      0.0 is false
 * 
 *  - Arrays -> Collection of same type of data
*/
typedef struct {
    int day;
    char month[10];
    int year;
} Date;

struct Date {
    int day;
    char month[10];
    int year;
};

int main() {
    struct Date today;
    today.day = 1;
    strcpy(today.month, "January");
    today.year = 2021;

    return 0;
}