#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char str[] = "";
    mx_str_reverse(str); //'str' now is "revo emag"
    printf("%s\n", str);
}

