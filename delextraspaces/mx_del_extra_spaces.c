#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

// void skip_spaces(const char *str, int *i)
// {
//     for (; mx_isspace(str[*i]); (*i)++) {}
// }

void count_spaces(const char *str, int *count)
{
    for (; mx_isspace(str[*i]); (*i)++) {}
}

char *mx_del_extra_spaces(const char *str)
{
    const char *s = mx_strtrim(str);
    if (!s)
        return NULL;
    int i = 0;
    int sp_count = 0;
    while (str[i])
    {
        skip_untilspace(s, &i);
        skip_spaces(s, &i);
        sp_count += 1;
    }
    
}

