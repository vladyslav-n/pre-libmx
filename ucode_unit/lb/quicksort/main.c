#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    //char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
    char *arr[] = {"666666", "333", "999999999", "1", "88888888", "4444", "55555", "7777777", "22"};
    printf("%d\n", mx_quicksort(arr, 0, 8));
    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", arr[i]);
    }    
}

