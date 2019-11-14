#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd)
{

    int res = 0;
    int read_bytes = 0;
    static t_tail tail;
    if (!tail.s)
        tail.s = mx_strnew(buf_size);
    //char *buf = (char*) malloc(sizeof(char) * buf_size);
    char *buf = mx_strnew(buf_size);
    char *buf_tmp = buf;
    char *s_tmp = tail.s;
    int ind_delim = -3;
    // char *curs_tail = NULL;
    // char *curs_buf = NULL;
    // char *superbuf = NULL;
    while ((read_bytes = read(fd, buf, buf_size)) == buf_size)
    {
        if ((ind_delim = mx_get_char_index(tail.s, delim)) >= 0)
        {
            mx_strncpy(*lineptr, tail.s, ind_delim);
            *lineptr += ind_delim;
            res += ind_delim;
            tail.s = mx_strjoin(tail.s + ind_delim + 1, buf);
            tail.len += buf_size - ind_delim - 1;
            
            free(s_tmp);
            s_tmp = tail.s;
            free(buf);
            buf = NULL;

            return res;
        }
        if ((ind_delim = mx_get_char_index(buf, delim)) >= 0)
        {

            mx_strcpy(*lineptr, tail.s);
            mx_strncpy(*lineptr + tail.len, buf, ind_delim);
            *lineptr += tail.len + ind_delim;
            res += tail.len + ind_delim;
            tail.s = mx_strdup(buf + ind_delim + 1);
            free(s_tmp);
            s_tmp = tail.s;
            free(buf);
            buf = NULL;

            return res;
        }
        else
        {

            mx_strcpy(*lineptr, tail.s);
            mx_strcpy(*lineptr + tail.len, buf);
            *lineptr += tail.len + buf_size;
            res += tail.len + buf_size;
            tail.s = mx_strnew(0);
            free(s_tmp);
            s_tmp = tail.s;

            continue;            
        }
        
    }

    if (errno) {
        free(buf);
        buf = NULL;

        return -2;
    }
    if (!res && !read_bytes) {
        free(buf);
        buf = NULL;
        return -1;
    }

    buf = mx_strndup(buf, read_bytes);
    free(buf_tmp);
    buf_tmp = NULL;
    buf_size = read_bytes;
    if ((ind_delim = mx_get_char_index(tail.s, delim)) >= 0)
    {
        mx_strncpy(*lineptr, tail.s, ind_delim);
        *lineptr += ind_delim;
        res += ind_delim;
        tail.s = mx_strjoin(tail.s + ind_delim + 1, buf);
        tail.len += buf_size - ind_delim - 1;
        
        free(s_tmp);
        s_tmp = tail.s;
        free(buf);
        buf = NULL;
        return res;
    }
    else if ((ind_delim = mx_get_char_index(buf, delim)) >= 0)
    {
        mx_strcpy(*lineptr, tail.s);
        mx_strncpy(*lineptr + tail.len, buf, ind_delim);
        *lineptr += tail.len + ind_delim;
        res += tail.len + ind_delim;
        tail.s = mx_strdup(buf + ind_delim + 1);
        free(s_tmp);
        s_tmp = tail.s;
        free(buf);
        buf = NULL;
        return res;
    }
    else
    {
        mx_strcpy(*lineptr, tail.s);
        mx_strcpy(*lineptr + tail.len, buf);
        *lineptr += tail.len + buf_size;
        res += tail.len + buf_size;
        tail.s = mx_strnew(0);
        free(s_tmp);
        s_tmp = tail.s;
    }
    free(buf);
    buf = NULL;
    return res;
}

