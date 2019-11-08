#include "pathFinder.h"

bool mx_isnum(const char *str) {
    while (*str) {
        if (!mx_isdigit(*str)) {
            return false;
        }
        str++;
    }
    return true;
}
