#include "pathFinder.h"

t_graph *mx_create_graph(int V) {
    t_graph *graph = malloc(sizeof(t_graph));

    graph->V = V;
    graph->array = malloc(V * sizeof(t_adj_list));
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}
