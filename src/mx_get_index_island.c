#include "pathFinder.h"

int mx_get_index_island(char **islands, char *island) {
    int index = 0;

    while (islands[index]) {
        if (!mx_strcmp(islands[index], island)) {
            return index;
        }
        index++;
    }
    return -1;
}
