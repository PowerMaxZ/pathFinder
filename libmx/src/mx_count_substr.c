#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (sub == NULL || str == NULL)
        return -1;
    int count = 0;
    if (mx_get_substr_index(str, sub) == -1)
        return count;
    while (mx_get_substr_index(str, sub) != -1) {
        count++;
        str += mx_get_substr_index(str, sub);
        str += mx_strlen(sub);
    }
    return count;
}
