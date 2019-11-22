#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    //char *str = mx_del_extra_spaces("\f  My name...     is  \r Neo  \t\n ");
    char *str = mx_del_extra_spaces("ZV\n\v\t\r\f\v   \n   \v  \t\r\f\v    7kIYyxUiva8GwMLykOxZquMP3l5Dm 09v5c");
    printf("%s\n", str);
    str = mx_del_extra_spaces("u5w8ZPIOrl0cNmSaI5\n\v\t\r\f\v   \n   \v  \t\r\f\v    W zDmR6qx64\n\v\t\r\f\v   \n   \v  \t\r\f\v    jUWLQHGw");
    printf("%s\n", str);
    // str = mx_del_extra_spaces("word   w d");
    // printf("%s\n", str);
}

