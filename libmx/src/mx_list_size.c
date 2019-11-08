#include "libmx.h"

int mx_list_size(t_list *list)
{
    int i = 0;
    while (list)
    {
        i++;
        list = list->next;
    }
    return i;
}
