#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str) {
        return NULL;
    }
    int left_spaces = 0;
    int right_spaces = 0;
    int length_str = mx_strlen(str);
    char *result = NULL;

    for (int i = 0; i < length_str; i++) {
        if (mx_isspace(str[i])) {
            left_spaces++;
            continue;
        }
        break;
    }
    for (int i = length_str - 1; i >= 0; i--) {
        if (mx_isspace(str[i])) {
            right_spaces++;
            continue;
        }
        break;
    }
    if (left_spaces == length_str) {
        return mx_strnew(0);
    }
    result = mx_strnew(length_str - left_spaces - right_spaces);
    return mx_strncpy(result, str + left_spaces, length_str - left_spaces - right_spaces);
}
