#include "pathFinder.h"

int mx_get_weight_path(char *path, int *matrix, int count_islands) {
    int index = 0;
    int result = 0;

    while (path[index + 1]) { 
        int weight = *(matrix + mx_ctoi(path[index]) * count_islands + mx_ctoi(path[index + 1]));
        if (weight == -1) {
            return 2000010000;
        }
        result += weight;
        index++;
    }
    return result;
}
