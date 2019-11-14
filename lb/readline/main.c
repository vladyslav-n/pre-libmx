#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    int fd = open("copy", O_RDONLY);
    char *s = (char*) calloc(1000, 1);
    int sum = 0;
    int buf = 0, buf_size = 20;
    char *reserv = s;
    while ((buf = mx_read_line(&s, buf_size, '*', fd)) > 0)
        sum += buf;
    printf("read chars = %d\n", sum);
    printf("%s\n", reserv);
    close(fd);
    //free(s);
}

