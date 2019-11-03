#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL && s2 != NULL) {
        int length = mx_strlen(s2);
        char *result = (char *)malloc(length);
        mx_strcpy(result, s2);
        return result;
    }
    if (s1 != NULL && s2 == NULL) {
        int length = mx_strlen(s1);
        char *result = (char *)malloc(length);
        mx_strcpy(result, s1);
        return result;
    }
    int length_s1 = mx_strlen(s1);
    int length_s2 = mx_strlen(s2);
    int length_both = length_s1 + length_s2;
    char *result = (char *)malloc(length_both);
    mx_strcpy(result, s1);
    int i = length_s1;
    for (int j = 0; s2[j]; j++) {
        result[i] = s2[j];
        i++;
    }
    return result;
}
