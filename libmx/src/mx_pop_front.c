#include "libmx.h"

void mx_pop_front(t_list **head)
{
    if (*head != NULL)
    {
        t_list *temp = *head, *tmp = temp->next;

        temp->data = NULL;
        free(temp);
        temp = NULL;

        *head = tmp;
    }
}
