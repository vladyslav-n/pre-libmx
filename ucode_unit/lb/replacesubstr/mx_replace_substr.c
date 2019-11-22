#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
    if (!str || !sub || !replace)
        return NULL;
    int sub_count = mx_count_substr(str, sub);
    if (!sub_count || !*sub || !*replace)
        return mx_strdup(str);
        
    int rep_len = mx_strlen(replace);
    int sub_len = mx_strlen(sub);
    char* s = mx_strnew(mx_strlen(str) 
            + (rep_len - sub_len) * sub_count);
    char *save = s;
    int sub_index = 0;
    
    for (int i = 0; i < sub_count; i++)
    {
        sub_index = mx_get_substr_index(str, sub);
        mx_strncpy(s, str, sub_index);
        mx_strcat(s, replace);
        str += sub_index + sub_len;
        s += sub_index + rep_len;
    }
    if (*str)
        mx_strcpy(s, str);
    return save;
}

