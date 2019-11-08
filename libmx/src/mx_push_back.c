#include "libmx.h"

void mx_push_back(t_list **list, void *data)
{
    if (*list == NULL)
    {
        t_list *node = mx_create_node(data);
        *list = node;
    }
    else
    {
        t_list *node = mx_create_node(data), *p = *list;
        while (p->next)
            p = p->next;
        p->next = node;
    }
}
