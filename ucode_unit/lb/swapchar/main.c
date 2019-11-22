#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    char str[] = "ONE";
    mx_swap_char(&str[0], &str[1]); //'str' now is "NOE"
    printf("%s\n", str);
    mx_swap_char(&str[1], &str[2]); //'str' now is "NEO"
    printf("%s\n", str);
}

