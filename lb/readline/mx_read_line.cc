#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd)
{
    int res = 0;
    char c = 0;
    //char *buf = (char*) malloc(sizeof(char) * buf_size);
    for (; read(fd, &c, 1) > 0; res++)
    {
        if (c == delim)
            break;
        *(*lineptr + res) = c;
    }
    if (errno)
        return -1;
    *lineptr +=res;
    return res;
    res = buf_size;
}

