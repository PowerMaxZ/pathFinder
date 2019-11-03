#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (*head == NULL)
        return;
    if ((*head)->next == NULL) {
        free((*head)->next);
        (*head)->next = NULL;
    }
    t_list *current = *head;
    while (current->next->next != NULL)
        current = current->next;
    free(current->next);
    current->next = NULL;
}