#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd)
{
    int res = 0;
    int read_bytes = 0;
    static char *tail = "";
    //char *buf = (char*) malloc(sizeof(char) * buf_size);
    char *buf = mx_strnew(buf_size);
    char *tmp = tail;
    int ind_delim = -3;
    while ((read_bytes = read(fd, buf, buf_size)) == buf_size)
    {
        if ((ind_delim = mx_get_char_index(tail, delim)) >= 0)
        {
            mx_strncpy(*lineptr, tail, ind_delim);
            res += ind_delim;
            tail = mx_strjoin(tail + ind_delim + 1, buf);
            free(tmp);
            tmp = tail;
            *lineptr += ind_delim;
            continue;
        }
        if ((ind_delim = mx_get_char_index(buf, delim)) >= 0)
        {
            mx_strcpy(*lineptr, tail);
            mx_strncpy(*lineptr + mx_strlen(*lineptr), buf, ind_delim);
            // mx_strncpy(*lineptr + mx_get_substr_index(*lineptr, 0), ind_delim);
            res += mx_strlen(tail) + ind_delim;
            tail = mx_strdup(buf + ind_delim + 1);
            free(tmp);
            tmp = tail;
            *lineptr += mx_strlen(*lineptr);
            continue;
        }
        mx_strcpy(*lineptr, tail);
        mx_strcpy(*lineptr, buf);
        res += mx_strlen(*lineptr);
        tail = mx_strnew(0);
        free(tmp);
        tmp = tail;
        *lineptr += mx_strlen(*lineptr);
    }
    if (errno)
        return -2;
    if (!res && !read_bytes)
        return -1;
    if ((ind_delim = mx_get_char_index(tail, delim)) >= 0)
        {
            mx_strncpy(*lineptr, tail, ind_delim);
            res += ind_delim;
            tail = mx_strjoin(tail + ind_delim + 1, buf);
            free(tmp);
            tmp = tail;
            *lineptr += ind_delim;
    
        }
    else    if ((ind_delim = mx_get_char_index(buf, delim)) >= 0)
        {
            mx_strcpy(*lineptr, tail);
            mx_strncpy(*lineptr + mx_strlen(*lineptr), buf, ind_delim);
            // mx_strncpy(*lineptr + mx_get_substr_index(*lineptr, 0), ind_delim);
            res += mx_strlen(tail) + ind_delim;
            tail = mx_strdup(buf + ind_delim + 1);
            free(tmp);
            tmp = tail;
            *lineptr += mx_strlen(*lineptr);

        }
    else {    mx_strcpy(*lineptr, tail);
        mx_strcpy(*lineptr, buf);
        res += mx_strlen(*lineptr);
        tail = mx_strnew(0);
        free(tmp);
        tmp = tail;
        *lineptr += mx_strlen(*lineptr);
    }
    return res;
}

