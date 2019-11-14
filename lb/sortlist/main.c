#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

void printlist(t_list *list)
{
    if (!list) {
        return;
    }
    while (list->next)
    {
        printf("%s\n", list->data);
        list = list->next;
    }
    printf("%s\n\n", list->data);
}
bool cmpr(void* s1, void *s2)
{
    if (mx_strlen(s1) > mx_strlen(s2))
    {
        return true;
    }
    return false;
    
}
int main()
{

    //char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    char *sarr[] = {"666666", "333", "999999999", "1", "88888888", "4444", "55555", "7777777", "22"};
    t_list *arr[9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = mx_create_node(sarr[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        arr[i]->next = arr[i + 1];
    }
    printf("before:\n");
    printlist(arr[0]);
//    mx_sort_list(arr[0], &cmpr);
    printf("after:\n");
    printlist(mx_sort_list(arr[0], &cmpr));
}

