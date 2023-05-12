#include "status.h"

static char * messages[] = {
    "",
    "MEMORY ALLOCATION ERROR",
    "FILE OPEN FAIL",
    "EMPTY COLLECTION",
    "UNKNOWN ERROR"
};

char * statusMessage(status s) {
    return s < ERRNULL ? messages[s] : messages[ERRNULL];
}