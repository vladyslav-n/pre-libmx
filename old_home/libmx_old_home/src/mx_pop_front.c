#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void mx_pop_front(t_list **head)
{
    if (!*head) {
        return;
    }
    t_list *tmp = *head;
    *head = (*head)->next;
    free(tmp);
    tmp = NULL;
}

