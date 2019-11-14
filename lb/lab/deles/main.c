#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define DEBUG

bool isspace(char c) {
    if (   c == '\t' 
        || c == '\n' 
        || c == '\v' 
        || c == '\r' 
        || c == '\f' 
        || c == ' ' )
        return 1;
    else
        return 0;
}

char *mx_strnew(const int size) {
    if (size >= 0)
    {
        char *str = (char*) malloc(size + 1);
            for (int i = 0; i <= size; i++) 
                str[i] = '\0';
        return str;
    }
    else return NULL;
}

size_t strlen_size_t(const char *s) {
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

char *strnew_size_t(size_t size) {
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
    if (len <= strlen_size_t(src) + 1)
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
    char *str1 = strnew_size_t(strlen_size_t(str));
    return mx_strcpy_size_t(str1, str);
}

char *strndup(const char *s1, size_t n)
{
    if (n >= strlen_size_t(s1))
        return mx_strdup_size_t(s1);
    char *dst = strnew_size_t(n);
    return mx_strncpy_size_t(dst, s1, n); 
}

void skip_spaces(const char *str, int *i)
{
    for (; isspace(str[*i]); (*i)++) {}
}

void skip_untilspace(const char *str, int *i)
{
    for (; !isspace(str[*i]) && str[*i]; (*i)++) {}
}

char *mx_strtrim(const char *str)
{
    if (!str)
        return NULL;
    int len = 0;
    skip_spaces(str, &len);
    int min_index = len;
    int nul_index = 0;
    while (str[len])
    {
        skip_untilspace(str, &len);
        nul_index = len;
        skip_spaces(str, &len);
    }
    return strndup(str + min_index, nul_index - min_index);
}

void skip_spaces_ncount(const char *str, int *i, int *count)
{
    for (; isspace(str[*i]); (*i)++) 
        *count += 1;
}

char *mx_del_extra_spaces(const char *str)
{
    const char *s = mx_strtrim(str);
    if (!s)
        return NULL;
    int i = 0;
    int sp_count = 0;
    int sp_total = 0;
    while (1) //while (str[i])
    {
        skip_untilspace(s, &i);
        if (!s[i])
            break;
        sp_count += 1;
        skip_spaces_ncount(s, &i, &sp_total);
    }
    // skip_untilspace(s, &i);
    int s_size = i;
    int fin_size = s_size - sp_total + sp_count;
    char *fin = strnew(fin_size);
    int j = 0;
    for (j = 0; j < fin_size; j++)
    {
        fin[j] = s[i];
        i++;
        if (!isspace(s[i]))
            continue;
        skip_spaces(s, &i);
    }
    free((void *)s);
    return fin;
}



int main()
{
    char *str = mx_del_extra_spaces("\f  My name...     is  \r Neo  \t\n ");
    printf("%s\n", str);
}

