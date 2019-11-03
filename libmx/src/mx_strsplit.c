#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) return NULL;
    int size = mx_count_words(s, c);
    char **res = (char **) malloc((size + 1) * sizeof (char *));
    int i_res = 0;
    int i_del = 0;

    if (size == 1) {
        res[0] = mx_strdup(s);
        res[1] = NULL;
        return res;
    }
    while (*s) {
        i_del = mx_get_char_index(s, c);
        i_del = i_del == -1 ? i_del = mx_strlen(s) : i_del;
        if (i_del) {
            res[i_res] = mx_strndup(s, i_del);
            s += mx_strlen(res[i_res]) - 1;
            i_res++;
        }
        s++;
    }
    res[i_res] = NULL;
    return res;
}
