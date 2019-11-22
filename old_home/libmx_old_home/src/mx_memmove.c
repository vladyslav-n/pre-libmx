#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void *mx_memmove(void *dst, const void *src, size_t len)
{
    //unsigned char *buf = (unsigned char *)malloc(sizeof(unsigned char) * len);
    void *restrict buf = (void *)malloc(sizeof(unsigned char) * len);
    mx_memcpy(buf, src, len);
    mx_memcpy(dst, buf, len);
    free(buf);
    return dst;
}

