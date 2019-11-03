#include "libmx.h"

char *mx_strnew(const int size) {
    char *res = malloc(size + 1);
    for (int i = 0; i < size + 1; i++) {
        res[i] = '\0';
    }
    return res;
}
