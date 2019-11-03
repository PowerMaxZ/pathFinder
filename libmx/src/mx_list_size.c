#include "libmx.h"

int mx_list_size(t_list *list) {
    if (list == NULL)
        return 0;
    int count = 0;
    while (list->next != NULL) {
        list = list->next;
        count++;
    }
    return count;
}
