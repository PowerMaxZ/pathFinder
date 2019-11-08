#include "libmx.h"

void mx_pop_back(t_list **head)
{
    if (*head != NULL)
    {
        t_list *p = *head;
        if (p->next == NULL)
        {
            p->data = NULL;
            free(p);
        }
        else
        {
            while (p->next->next)
                p = p->next;
            p->next->data = NULL;
            free(p->next);
            p->next = NULL;
        }
    }
}
