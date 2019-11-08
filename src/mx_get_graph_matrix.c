#include "pathFinder.h"

t_graph *mx_get_graph_matrix(int *matrix, int count_islands) {
    t_graph *res_graph = mx_create_graph(count_islands);

    for (int i = 0; i < count_islands; i++) {
        for (int j = 0; j < count_islands; j++) {
            if (*(matrix + i * count_islands + j) != -1) {
                mx_add_edge(res_graph, i, j);
            }
        }
    }
    return res_graph;
}
