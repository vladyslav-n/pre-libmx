#include "../inc/libmx.h"

size_t mx_strlen_size_t(const char *s) {
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

char *mx_strnew_size_t(size_t size) {
    if (size >= 0)
    {
        char *str = (char*) malloc(size + 1);
            for (size_t i = 0; i <= size; i++) 
                str[i] = '\0';
        return str;
    }
    else return NULL;
}

char *mx_strcpy_size_t(char *dst, const char *src) {
    size_t i = 0;
    while(src[i]){
        dst[i] = src[i];
        i++;
    }
        dst[i] = src[i];
    return dst;
}

char *mx_strncpy_size_t(char *dst, const char *src, size_t len) {
    size_t i = 0;
    if (len <= mx_strlen_size_t(src) + 1)
    {
        for (; i < len; i++)
            dst[i] = src[i];
        return dst;
    }
    else
    {
        for (; src[i]; i++)
            dst[i] = src[i];
        for (; i < len; i++)
            dst[i] = '\0';
        return dst;
    }
}



char *mx_strdup_size_t(const char *str) 
{
    char *str1 = mx_strnew_size_t(mx_strlen_size_t(str));
    return mx_strcpy_size_t(str1, str);
}

char *mx_strndup(const char *s1, size_t n)
{
    if (n >= mx_strlen_size_t(s1))
        return mx_strdup_size_t(s1);
    char *dst = mx_strnew_size_t(n);
    return mx_strncpy_size_t(dst, s1, n); 
}

