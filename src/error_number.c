#include "pathFinder.h"

int error_number(char **file_d) {
    int number = mx_atoi(file_d[0]);
    char **islands = malloc(sizeof(char *) * (number + 1));
    islands[number] = NULL;
    for (int i = 0; islands[i]; i++) {
        islands[i] = "";
    }
    for (int i = 1; file_d[i]; i++) {
        int length_s1 = mx_get_char_index(file_d[i], '-');
        int length_s2 = mx_get_char_index(file_d[i], ',') - length_s1 - 1;
        char *s1 = (char *)mx_strnew(length_s1);
        s1 = mx_strncpy(s1, file_d[i], length_s1);
        char *s2 = (char *)mx_strnew(length_s2);
        s2 = mx_strncpy(s2, file_d[i] + length_s1 + 1, length_s2);
        if (mx_strcmp(s1, s2) == 0) {
            mx_printstr("error: line ");
            mx_printint(i);
            mx_printstr(" isn't valid");
            return 0;
        }
        int flag = 0;
        for (int i = 0; i < number; i++) {
            if (mx_strcmp(islands[i], "") == 0) {
                islands[i] = (char *)mx_strnew(length_s1);
                islands[i] = mx_strcpy(islands[i], s1);
                flag = 1;
                break;
            }
            if (mx_strcmp(s1, islands[i]) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            mx_printstr("error: invalid number of islands");
            return 0;
        }
        flag = 0;
        for (int i = 0; i < number; i++) {
            if (mx_strcmp(islands[i], "") == 0) {
                islands[i] = (char *)mx_strnew(length_s2);
                islands[i] = mx_strcpy(islands[i], s2);
                flag = 1;
                break;
            }
            if (mx_strcmp(s2, islands[i]) == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            mx_printstr("error: invalid number of islands");
            return 0;
        }
    }
    for (int i = 0; islands[i]; i++) {
        mx_printstr(islands[i]);
        mx_printstr("\n");
    }
    return 1;
}
