#include "../inc/libmx.h"

bool is_substr(const char *haystack, const char *needle) 
{
    for (int i = 0; needle[i]; i++)
        if (needle[i] != haystack[i])
            return 0;
        return 1;
}

int mx_count_substr(const char *str, const char *sub)
{
    if (!sub || !str)
        return -1;
    if (!sub[0])
        return 0;
    int count = 0;
    int sublen = mx_strlen(sub);
    for (int i = 0; str[i]; i++)
        if (is_substr(str + i, sub))
        {
            count +=1;
            i += sublen - 1;
        }
    return count;
}

