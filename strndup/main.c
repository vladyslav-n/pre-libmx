#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char *s4 = mx_strndup("12345", 0);
    char *s5 = mx_strndup("12345", 5);
    char *s6 = mx_strndup("12345", 6);
    char *s7 = mx_strndup("12345", 7);
    char *s8 = mx_strndup("12345", 8);
    s4 = NULL;
    s5 = NULL;
    s6 = NULL;
    s7 = NULL;
    s8 = NULL;
}

