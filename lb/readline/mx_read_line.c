#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd)
{
    int res = 0;
    static 
    //char *buf = (char*) malloc(sizeof(char) * buf_size);
    char *buf = mx_strnew(buf_size - 1);
    for (; read(fd, buf, buf_size) == buf_size; res++)
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

