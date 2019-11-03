#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (n == 0)
        return NULL;
    char *res = (char *)malloc(n);
    mx_strncpy(res, s1, n);
    return res;
}
