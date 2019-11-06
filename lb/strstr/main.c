#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char s1[20] = "123458059684050";
    char s2[] = "123458059684050";
    char *str = mx_strstr(s1, s2);
    printf("%s\n\t2\f\f\v2", str);
}

