#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char *str = mx_del_extra_spaces("\f  My name...     is  \r Neo  \t\n ");
    // char *str = mx_del_extra_spaces("");
    printf("%s\n", str);
    str = mx_del_extra_spaces("word");
    printf("%s\n", str);
    str = mx_del_extra_spaces("word   w d");
    printf("%s\n", str);
}

