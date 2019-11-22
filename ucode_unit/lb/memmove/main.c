#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char s1[] = "---------------";
    char s2[] = "";
    char *str = mx_memmove(s1 + 4, s2, 3);
    printf("%s\n", str);
}

