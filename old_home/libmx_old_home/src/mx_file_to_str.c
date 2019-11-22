#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

char *mx_file_to_str(const char *file)
{
    int fd = open(file, O_RDONLY);
    #ifdef DEBUG
    printf("errno = %d\n", errno);
    printf("fd = %d\n", fd);
    #endif

    if (errno)
        return NULL;
    char c = 0;
    int len = 0;
    for (; (c = read(fd, &c, 1)); len++) {}
    close(fd);
    char *s = mx_strnew(len);
    fd = open(file, O_RDONLY);
    for (int i = 0; i < len; i++) 
        read(fd, s + i, 1); 
    close(fd);
    #ifdef DEBUG
    printf("errno = %d\n", errno);
    printf("fd = %d\n", fd);
    #endif
    if (!errno)
        return s;
    return NULL;
}

