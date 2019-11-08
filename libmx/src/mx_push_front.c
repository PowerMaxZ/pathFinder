#include "libmx.h"

void mx_push_front(t_list **list, void *data)
{
    t_list *node = mx_create_node(data);
    if (list)
        node->next = *list;
    else
        node->next = NULL;
    *list = node;
}
