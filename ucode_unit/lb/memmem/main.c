#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char s1[] = "_____\0 1111111111";
    char s2[] = "";
    char *str = mx_memmem(s1, 18, s2, 1);
    printf("%s\n", str);
}

