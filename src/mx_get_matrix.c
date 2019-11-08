#include "pathFinder.h"

static void mx_add_pair(int *matrix, char **islands, char *line);

int *mx_get_matrix(char **islands, char *text_of_file) {
    int count_islands = mx_arr_size(islands);
    int len = sizeof(int *) * count_islands + sizeof(int) * count_islands * count_islands;
    int *matrix = malloc(len);
    char **lines = mx_strsplit(text_of_file, '\n');
    for (int i = 0; i < count_islands; i++) {
        for (int j = 0; j < count_islands; j++) {
            *(matrix + i * count_islands + j) = -1;
        }
    }

    lines++;
    while (*lines) {
        mx_add_pair(matrix, islands, *lines);
        lines++;
    }
    return matrix;
}

static void mx_add_pair(int *matrix, char **islands, char *line) {
    int first_index = mx_get_char_index(line, '-');
    int second_index = mx_get_char_index(line, ',');
    int third_index = mx_strlen(line);
    int count_islands = mx_arr_size(islands);
    char *new_first_island = NULL;
    char *new_second_island = NULL;
    char *length_bt_islands = NULL;

    new_first_island = mx_strnew(first_index);
    new_second_island = mx_strnew(second_index - first_index - 1);
    length_bt_islands  = mx_strnew(third_index - second_index - 1);
    mx_strncpy(new_first_island, line, first_index);
    mx_strncpy(new_second_island, line + first_index + 1, second_index - first_index - 1);
    mx_strncpy(length_bt_islands, line + second_index + 1, third_index - second_index - 1);

    int length = mx_atoi(length_bt_islands);
    int first_el = mx_get_index_island(islands, new_first_island);
    int second_el = mx_get_index_island(islands, new_second_island);

    *(matrix + first_el * count_islands + second_el) = length;
    *(matrix + second_el * count_islands + first_el) = length;
}
