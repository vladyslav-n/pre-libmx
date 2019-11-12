#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
    unsigned char *d = dst;
    unsigned char *s = (unsigned char *)src;
    for (size_t i = 0; i < n; i++)
    {
        if (*s == c)
        {
            *d++ = c;
            return d;
        }
        *d++ = *s++;
    }
    return NULL;
}

