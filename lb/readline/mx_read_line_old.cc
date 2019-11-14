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
#ifdef DEBUG
printf("Succsess0\n");
printf("read bytes = %d\n", read_bytes);
#endif

        if ((ind_delim = mx_get_char_index(tail.s, delim)) >= 0)
        {
#ifdef DEBUG
printf("LEVEL2Succsess0\n");
printf("ind_delim = %d\n", ind_delim);
#endif
            mx_strncpy(*lineptr, tail.s, ind_delim);
            *lineptr += ind_delim;
            res += ind_delim;
            tail.s = mx_strjoin(tail.s + ind_delim + 1, buf);
            tail.len += buf_size - ind_delim - 1;
            
            if (s_tmp) free(s_tmp);
            s_tmp = tail.s;
            free(buf);
            buf = NULL;
#ifdef DEBUG
printf("Succsess1\n");
#endif

            return res;
        }
        if ((ind_delim = mx_get_char_index(buf, delim)) >= 0)
        {
#ifdef DEBUG
printf("LEVEL2Succsess1\n");
printf("ind_delim = %d\n", ind_delim);
#endif

            mx_strcpy(*lineptr, tail.s);
            mx_strncpy(*lineptr + tail.len, buf, ind_delim);
            *lineptr += tail.len + ind_delim;
            res += tail.len + ind_delim;
            tail.s = mx_strdup(buf + ind_delim + 1);
            if (s_tmp) free(s_tmp);
            s_tmp = tail.s;
            free(buf);
            buf = NULL;
#ifdef DEBUG
printf("Succsess2\n");
#endif

            return res;
        }
        else
        {
#ifdef DEBUG
printf("LEVEL2Succsess2\n");
printf("ind_delim = %d\n", ind_delim);
#endif

            mx_strcpy(*lineptr, tail.s);
#ifdef DEBUG
printf("bug is after this\n");
printf("s = %s\n", *lineptr);
#endif
            mx_strcpy(*lineptr + tail.len, buf);
            *lineptr += tail.len + buf_size;
            res += tail.len + buf_size;
            tail.s = mx_strnew(0);
            free(s_tmp);
            s_tmp = tail.s;
#ifdef DEBUG
printf("Succsess3\n");
#endif

            continue;            
        }
        
    }
    if (errno) {
        free(buf);
        buf = NULL;
#ifdef DEBUG
printf("Succsess4\n");
#endif

        return -2;
    }
    if (!res && !read_bytes) {
        free(buf);
        buf = NULL;
#ifdef DEBUG
printf("Succsess5\n");
#endif

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
        
        if (s_tmp) free(s_tmp);
        s_tmp = tail.s;
        free(buf);
        buf = NULL;
#ifdef DEBUG
printf("Succsess6\n");
#endif

        return res;
    }
    else if ((ind_delim = mx_get_char_index(buf, delim)) >= 0)
    {
        mx_strcpy(*lineptr, tail.s);
        mx_strncpy(*lineptr + tail.len, buf, ind_delim);
        *lineptr += tail.len + ind_delim;
        res += tail.len + ind_delim;
        tail.s = mx_strdup(buf + ind_delim + 1);
        if (s_tmp) free(s_tmp);
        s_tmp = tail.s;
        free(buf);
        buf = NULL;
#ifdef DEBUG
printf("Succsess7\n");
#endif

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
#ifdef DEBUG
printf("Succsess8\n");
#endif

    return res;
}

