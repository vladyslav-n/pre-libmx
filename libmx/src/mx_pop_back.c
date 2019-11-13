#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void mx_pop_back(t_list **head)
{
    if (!*head) {
        return;
    }
//    t_list** list_save = list;
    while ((*head)->next) {
        head = &((*head)->next);
    }
    free(*head);
    *head = NULL;
}

