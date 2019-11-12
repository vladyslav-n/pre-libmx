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

void quicksort_void(char **arr, int left, int right, int *count)
{
    if (right - left < 1)
        return;
    int pivot  = mx_strlen(arr[left]);
    int wall = right;
    for (int i = right; i > left; i--)
    {
        if (mx_strlen(arr[i]) > pivot)
        {
            if (i != wall)
            {
            swap(&arr[i], &arr[wall]);
            (*count)++;
            }
            wall--;
        }
    }
    if (wall != left)
    {
        swap(&arr[left], &arr[wall]);
        (*count)++;
    }
    quicksort_void(arr, left, wall - 1, count);
    quicksort_void(arr, wall + 1, right, count);
}

int mx_quicksort(char **arr, int left, int right)
{   
    int count = 0;
    if (!arr)
        return -1;
    quicksort_void(arr, left, right, &count);
    return count;
}

