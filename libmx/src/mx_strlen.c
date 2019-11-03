#include "libmx.h"

int mx_strlen(const char *s) {
    if (s == NULL)
	    return 0;
    int k = 0;
    while (s[k] != '\0') {
	    k++;
    }
    return k;
}
