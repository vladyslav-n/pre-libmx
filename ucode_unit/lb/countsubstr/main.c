#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char s1[] = "";
    char *s2 = "3";
    int str = mx_count_substr(s1, s2);
    printf("%d", str);
}

