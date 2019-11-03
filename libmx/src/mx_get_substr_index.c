#include "../inc/libmx.h"

bool is_substr(const char *haystack, const char *needle) 
{
    for (int i = 0; needle[i]; i++)
        if (needle[i] != haystack[i])
            return 0;
        return 1;
}

int mx_get_substr_index(const char *str, const char *sub)
{
    if (!sub || !str)
        return -2;
    if (!sub[0])
        return 0;
    for (int i = 0; str[i]; i++)
        if (is_substr(str + i, sub))
            return i;
    return -1;
}

