#include "libmx.h"

int mx_strlen(const char *s);

void mx_printstr(const char *s) {
    int length = mx_strlen(s);
    write(1, s, length);
}
