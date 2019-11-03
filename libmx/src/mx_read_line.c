#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    if (fd < 0) return -1;
    *lineptr = mx_strnew(buf_size);
    if (buf_size == 0) return 0;
    char buf = '\0';
    int k = 0;
    int i = 0;
    int n = read(fd, &buf, sizeof(buf));
    while (n > 0) {
        char *line = mx_strnew(buf_size);
        for (i = 0; i < buf_size && n > 0; i++) {
            if (buf == delim) {
                line[i] = '\0';
                *lineptr = mx_strjoin(*lineptr, line);
                free(line);
                return k;
            }
            line[i] = buf;
            k++;
            n = read(fd, &buf, sizeof(buf));
        }
        *lineptr = mx_strjoin(*lineptr, line);
        free(line);
    }
    return k;
}
