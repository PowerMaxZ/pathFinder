#include "pathFinder.h"

static int mx_min(int a, int b);

int *mx_get_paths(int *matrix, char **islands) {
    int size_islands = mx_arr_size(islands);
    int len = sizeof(int *) * size_islands + sizeof(int) * size_islands * size_islands;
    int *m_p = malloc(len);

    for (int i = 0; i < size_islands; i++) {
        for (int j = 0; j < size_islands; j++) {
            *(m_p + i * size_islands + j) =  *(matrix + i * size_islands + j);
        }
    }
    for (int k = 0; k < size_islands; k++) {
        for (int i = 0; i < size_islands; i++) {
            for (int j = 0; j < size_islands; j++) {
                if (i != j && *(m_p + i * size_islands + k) != -1 &&
                    *(m_p + k * size_islands + j) != -1) {
                    if (*(m_p + i * size_islands + j) == -1) {
                        *(m_p + i * size_islands + j) = *(m_p + i * size_islands + k) + *(m_p + k * size_islands + j);
                    }
                    else {
                        *(m_p + i * size_islands + j) = mx_min(
                            *(m_p + i * size_islands + j),
                            *(m_p + i * size_islands + k) +
                            *(m_p + k * size_islands + j));
                    }
                }
            }
        }
    }
    return m_p;
}

static int mx_min(int a, int b) {
    if (b > a) {
        return a;
    }
    return b;
}
