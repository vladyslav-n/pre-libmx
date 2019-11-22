#include <stdlib.h>
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);

char *mx_strjoin(const char *s1, const char *s2)
{
    if (!s1 && !s2)
        return NULL;
    if (!s1 && s2)
        return mx_strdup(s2);
    if (!s2 && s1)
        return mx_strdup(s1);
    char *str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    str = mx_strcpy(str, s1);
    str = mx_strcat(str, s2);
    return str;
}

