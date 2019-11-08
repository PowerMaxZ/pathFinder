#include "pathFinder.h"

static void mx_get_all_paths(int u, int d, bool *visited, int *path, int path_index, t_graph *graph, t_list *paths);

t_list *mx_get_path_bt_islands(t_graph *graph, int i1, int i2, int count_islands) {
    bool *visited = malloc(sizeof(bool) * count_islands);
    int *path = malloc(sizeof(int) * count_islands);
    int path_index = 0;
    t_list *result_paths = mx_create_node(".");

    for (int i = 0; i < count_islands; i++) {
        visited[i] = false;
    }
    mx_get_all_paths(i1, i2, visited, path, path_index, graph, result_paths);
    return result_paths;
}

static void mx_get_all_paths(int u, int d, bool *visited, int *path, int path_index, t_graph *graph, t_list *paths) {
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if (u == d && path_index != 1) {
        char *str = mx_strnew(path_index);
        for (int i = 0; i < path_index; i++) {
            mx_strcat(str, mx_itoa(path[i]));
        }
        mx_push_back(&paths, str);
    }
    else {
        for (t_adj_list_node *i = graph->array[u].head; i != NULL; i = i->next) {
            if (!visited[i->dest]) {
                mx_get_all_paths(i->dest, d, visited, path, path_index, graph, paths);
            }
        }
    }
    path_index--;
    visited[u] = false;
}
