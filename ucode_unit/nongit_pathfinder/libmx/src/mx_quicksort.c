#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void swap(char **s1, char **s2)
{
    char *tmp;
    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int mx_quicksort(char **arr, int left, int right)
{   
    if (!arr)
        return -1;
    int count = 0;
    int i = left, j = right;
    int pivot = mx_strlen(arr[(left + right) / 2]);

    /* partition */

    while (i <= j) {
        while (mx_strlen(arr[i]) < pivot)
            i++;
        while (mx_strlen(arr[j]) > pivot)
            j--;
        if (i <= j) {
            if (i != j) {
                swap(&arr[i], &arr[j]);
                count += 1;
            }
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        count += mx_quicksort(arr, left, j);
    if (i < right)
        count += mx_quicksort(arr, i, right);
    return count;
}

