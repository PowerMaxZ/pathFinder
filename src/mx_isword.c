#include "pathFinder.h"

bool mx_isword(const char *str) {
    while (*str) {
        if (!mx_isletter(*str)) {
            return false;
        }
        str++;
    }
    return true;
}
