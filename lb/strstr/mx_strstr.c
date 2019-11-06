#include "../inc/libmx.h"

bool is_substr(const char *haystack, const char *needle) 
{
    for (int i = 0; needle[i]; i++)
        if (needle[i] != haystack[i])
            return 0;
        return 1;
}

char *mx_strstr(const char *haystack, const char *needle)
{
    if (!needle[0])
        return (char *)haystack;
    for (int i = 0; haystack[i]; i++)
        if (is_substr(haystack + i, needle))
            return (char *)haystack + i;
    return NULL;
}

