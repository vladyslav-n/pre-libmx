#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    int fd = open("copy", O_RDONLY);
    char *s = (char*) calloc(1000, 1);
    int sum = 0;
    int buf = 0;
    char *reserv = s;
    while ((buf = mx_read_line(&s, 20, '*', fd)))
        sum += buf;
    printf("read chars = %d\n", sum);
    printf("%s\n", reserv);
    close(fd);
    //free(s);
}

