#include "../inc/libmx.h"

char *mx_strdup(const char *str) 
{
    // if (NULL == str)
    //     return NULL;
    char *str1 = mx_strnew(mx_strlen(str));
    // if (NULL == str1)
    //     return NULL;
    return mx_strcpy(str1, str);
}

