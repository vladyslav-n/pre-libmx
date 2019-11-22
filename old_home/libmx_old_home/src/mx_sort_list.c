#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void swap_nodes(t_list **n1, t_list **n2)
{
    t_list *tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void quicksort_list(t_list **list, bool (*cmp)(void *, void *), int left, int right)
{
    int i = left, j = right;
    void *pivot = list[(left + right) / 2]->data;

    /* partition */

    while (i <= j) {
        while ((*cmp)(pivot, list[i]->data)) 
            i++;
        while ((*cmp)(list[j]->data, pivot))
            j--;
        if (i <= j) {
            if (i != j) {
                swap_nodes(&list[i], &list[j]);
            }
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        quicksort_list(list, cmp, left, j);
    if (i < right)
        quicksort_list(list, cmp, i, right);
    return;
}


t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{   
//    t_list *list = lst;
    int size = mx_list_size(lst);
    t_list **arr = (t_list**) malloc(sizeof(t_list*) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = lst;
        lst = lst->next;
    }
    quicksort_list(arr, cmp, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        arr[i]->next = arr[i + 1];
    }
    arr[size - 1]->next = NULL;
    t_list *save = arr[0];
    free(arr);
    arr = NULL;
    return save;
}

