#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *string;

    if (s == NULL)
        return NULL;
    string = (void *)s;
    while (n > 0) {
        if (string[n] == (char)c)
            return &string[n];
        n--;
    }
    return NULL;
}
