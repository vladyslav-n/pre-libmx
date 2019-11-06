#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    // const char *s = "**Good bye,**Mr.*Anderson.****";
    // char **arr = mx_strsplit(s, '*');  // arr = ["Good bye,", "Mr.", "Anderson."]
    const char *s = "     Knock, knock,    Neo.   ";
    char **arr = mx_strsplit(s, ' ');  // arr = ["Knock,", "knock,", "Neo."]
    mx_print_strarr(arr, "\n");
}

