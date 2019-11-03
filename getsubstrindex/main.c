#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char s1[20] = "123458059684050";
    char *s2 = NULL;
    int str = mx_get_substr_index(s1, s2);
    printf("%d", str);
}

