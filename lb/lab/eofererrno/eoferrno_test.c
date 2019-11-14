#include "../inc/libmx.h"
#include <stdio.h>

void eoferrno_test(const char *file)
{
    char c = 0;
    int len = 0;
    int fd = open(file, O_RDONLY);
    printf("errno after opening = %d\n", errno);
    printf("fd = %d\n", fd);
    for (; read(fd, &c, 1); len++) {}
    printf("errno after reaching eof = %d\n", errno);
    printf("len = %d\n", len);
    read(fd, &c, 1);
    len = 0;
    printf("errno after reading at eof = %d\n", errno);
    printf("len = %d\n", len);
    close(fd);
}

