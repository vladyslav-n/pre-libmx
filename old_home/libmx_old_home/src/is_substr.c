#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

bool is_substr(const char *haystack, const char *needle) 
{
    for (int i = 0; needle[i]; i++)
        if (needle[i] != haystack[i])
            return 0;
        return 1;
}

