#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL || !*str)
        return -1;
    const char *tmp = str;
    int count = 0;
    while (*tmp != '\0') {
        for (int i = 0; str[i] == c && str[i]; i++) {
            str++;
        }
        tmp = str;
        if (*tmp == '\0')
            return 0;
        for (int i = 0; tmp[i] != c && tmp[i]; i++) {
            str++;
        }
        tmp = str;
        count++;
    }
    return count;
}
