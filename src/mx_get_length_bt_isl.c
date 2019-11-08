#include "pathFinder.h"

int mx_get_length_bt_isl(int *matrix, char **islands, char *i1, char *i2) {
    int first_el = mx_get_index_island(islands, i1);
    int second_el = mx_get_index_island(islands, i2);
    int count_islands = mx_arr_size(islands);

    return *(matrix + second_el * count_islands + first_el);
}
