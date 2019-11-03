#include "pathFinder.h"

static int line_error_check(char *str);

char** file_error_check(char *str) {
    char **islands = mx_strsplit(str, '\n');
    for (int i = 0; islands[0][i]; i++) {
        if (mx_isdigit(islands[0][i]) == 0) {
            mx_printstr("error: line 1 isn't valid");
            return NULL;
        }
    }
    for (int i = 1; islands[i]; i++) {
        if (line_error_check(islands[i]) == 0) {
            mx_printstr("error: line ");
            mx_printint(i);
            mx_printstr(" isn't valid");
            return NULL;
        }
    }
    return islands;
}

static int line_error_check(char *str) {
    int length = mx_strlen(str);
    if (length < 5)
        return 0;
    int i = 0;
    while(isletter(str[i]))
        i++;
    if (str[i] != '-' || i == 0)
        return 0;
    i++;
    int count = i;
    while (isletter(str[i]))
        i++;
    if (str[i] != ',' || count - i == 0)
        return 0;
    i++;
    count = i;
    while (mx_isdigit(str[i]) && str[i])
        i++;
    if (count - i == 0)
        return 0;
    return 1;
}
