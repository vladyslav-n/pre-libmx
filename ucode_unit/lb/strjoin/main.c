#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    const char *str1 = "this";
    const char *str2 = "dodge ";
    const char *str3 = NULL;
    printf("%s\n", mx_strjoin(str2, str1));
    printf("%s\n", mx_strjoin(str1, str3)); //returns "this"
    printf("%s\n", mx_strjoin(str3, str3)); //returns NULL
    printf("%s\n", mx_strjoin("", ""));

}

