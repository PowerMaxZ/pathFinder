#include "libmx.h"

bool mx_isspace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\f'
            || c == '\v' || c == '\r')
        return true;
    return false;
}
