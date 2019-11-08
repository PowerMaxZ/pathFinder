#include "pathFinder.h"

t_adj_list_node *mx_new_adj_list_node(int dest) {
    t_adj_list_node *new_node = malloc(sizeof(t_adj_list_node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}
