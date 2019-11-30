#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
    int res = 0;
    size_t read_bytes = 0;
    static t_str_len tail;
    if (!tail.s) {
        tail.s = mx_strnew(buf_size);
    }
    char *s_tmp = tail.s;
    char *buf = mx_strnew(buf_size);
    char *buf_tmp = buf;
    int ind_delim = -3;
    char flag = -1;

    read_bytes = read(fd, buf, buf_size);
    
    /* error case */
    if (errno) {
        free(buf);
        buf = NULL;
        return -2;
    }

    while (read_bytes >= 0)
    {
        /* case when we read all buf_size chars */
        if (read_bytes == buf_size) {
            if (flag == 3) {
                flag = -1; 
            }

            if ((ind_delim = mx_get_char_index(tail.s, delim)) >= 0) {
                mx_strncpy(*lineptr, tail.s, ind_delim);
                *lineptr += ind_delim;
                res += ind_delim;
                tail.s = mx_strjoin(tail.s + ind_delim + 1, buf);
                tail.len += buf_size - ind_delim - 1;
            }
            else if ((ind_delim = mx_get_char_index(buf, delim)) >= 0) {
                mx_strcpy(*lineptr, tail.s);
                mx_strncpy(*lineptr + tail.len, buf, ind_delim);
                *lineptr += tail.len + ind_delim;
                res += tail.len + ind_delim;
                tail.s = mx_strdup(buf + ind_delim + 1);
                tail.len = buf_size - ind_delim - 1;
            }
            else {
                mx_strcpy(*lineptr, tail.s);
                mx_strcpy(*lineptr + tail.len, buf);
                *lineptr += tail.len + buf_size;
                res += tail.len + buf_size;
                tail.s = mx_strnew(0);
                tail.len = 0;
                if (flag == -1) {
                    flag = 3; 
                }
            }
            free(s_tmp);
            s_tmp = tail.s;
            if (flag == 3) {
                read_bytes = read(fd, buf, buf_size);
                continue;
            }
            break;
        }

        /* case when we read less than buf_size chars but not 0 */
        else if (read_bytes) {
            buf = mx_strndup(buf, read_bytes);
            free(buf_tmp);
            buf_tmp = NULL;
            buf_size = read_bytes;
            flag = -2;
            continue;
        }

        /* case when cursor is at the EOF */
        if (!res) {
            free(buf);
            buf = NULL;
            if (!tail.s[0])
                return -1;
            while (tail.s[0]) {
                if ((ind_delim = mx_get_char_index(tail.s, delim)) >= 0) {
                    mx_strncpy(*lineptr, tail.s, ind_delim);
                    *lineptr += ind_delim;
                    res += ind_delim;
                    tail.s = mx_strdup(tail.s + ind_delim + 1);
                    tail.len -= ind_delim + 1;
                    free(s_tmp);
                    s_tmp = tail.s;
                    continue;
                }
                break;
            }
            mx_strcpy(*lineptr, tail.s);
            *lineptr += tail.len;
            res += tail.len;
            tail.s = mx_strnew(0);
            tail.len = 0;
            free(s_tmp);
            s_tmp = tail.s;
            return res;
        }
        else {
            break;
        }
    }
    free(buf);
    buf = NULL;
    return res;
}

