#include "libmx.h"

static void swap(t_list *s1, t_list *s2);

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int size = mx_list_size(lst);
    t_list *current = lst;
    for (int i = 0; i < size; i++) {
        current = lst;
        if (lst || lst->next) {
            while (current->next) {
                if (cmp(current->data, current->next)) {
                    swap(current, current->next);
                }
                current = current->next;
            }
        }
    }
    return lst;
}

static void swap(t_list *s1, t_list *s2) {
    void *tmp = s1->data;
    s1->data = s2->data;
    s2->data = tmp;
}
