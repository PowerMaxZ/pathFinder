#include "libmx.h"

void mx_pop_front(t_list **head) {
    if (*head == NULL)
        return;
    t_list *temp = *head;
    *head = temp->next;
    free(temp);
    temp = NULL;
}
