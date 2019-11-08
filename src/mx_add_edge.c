#include "pathFinder.h"

void mx_add_edge(t_graph *graph, int src, int dst) {
    t_adj_list_node *new_node = mx_new_adj_list_node(dst);

    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    new_node = mx_new_adj_list_node(src);
    new_node->next = graph->array[dst].head;
    graph->array[dst].head = new_node;
}
