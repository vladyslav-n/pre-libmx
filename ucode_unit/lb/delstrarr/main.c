#include "../inc/libmx.h"
#include <stdio.h>
#include <string.h>
#define DEBUG

int main()
{
    char **arr = (char**) malloc(sizeof(char*) * 5);
    arr[4] = NULL;
    for (int i = 0; i < 4; i++)
    {
        arr[i] = strdup("12345");
    }
    mx_print_strarr(arr, "\n");
    mx_del_strarr(&arr);
}

