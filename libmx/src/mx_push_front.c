#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *current = mx_create_node(data);
    current->next = *list;
    *list = current;
}
