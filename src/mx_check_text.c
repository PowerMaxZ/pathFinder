#include "pathFinder.h"

static bool mx_isvalid_line(char *line);

bool mx_check_text(char *text) {
    char **lines = mx_strsplit(text, '\n');
    int index = 0;

    if (!mx_isnum(lines[0])) {
        mx_printerr(INVLD_FRST_LINE, NULL);
    }
    index++;
    while (lines[index]) {
        if (!mx_isvalid_line(lines[index])) {
            mx_printerr(INVLD_LINE, mx_itoa(index + 1));
        }
        index++;
    }
    return true;
}

static bool mx_isvalid_line(char *line) {
    int first_index = 0;
    int second_index = 0;
    int third_index = 0;
    
    while (mx_isletter(line[first_index])) {
        first_index++;
    }
    if (!first_index || line[first_index++] != '-') {
        return false;
    }
    second_index = first_index;
    while (mx_isletter(line[second_index])) {
        second_index++;
    }
    if (second_index == first_index || line[second_index++] != ',') {
        return false;
    }
    third_index = second_index;
    while (mx_isdigit(line[third_index])) {
        third_index++;
    }
    if (line[third_index]) {
        return false;
    }
    return true;
}
