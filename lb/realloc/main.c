#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char *ptr = calloc(5, 1);
    strcpy(ptr ,"12345");
    printf("memory 1 = %x\n", (int)ptr);
    printf("%s\n", ptr);
    ptr = mx_realloc(ptr, 10);
    printf("memory 2 = %x\n", (int)ptr);
    strcpy(ptr ,"123456789---");
    printf("%s\n", ptr);
    ptr = mx_realloc(ptr, 2);
    printf("memory 3 = %x\n", (int)ptr);
    printf("%s\n", ptr);
    ptr = mx_realloc(NULL, 5);
    strcpy(ptr ,"123456789");
    printf("memory 4 = %x\n", (int)ptr);
    printf("%s\n", ptr);
}

