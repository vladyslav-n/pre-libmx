#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void skip_spaces_ncount(const char *str, int *i, int *count)
{
    for (; mx_isspace(str[*i]); (*i)++) 
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
    while (1)
    {
        skip_untilspace(s, &i);
        if (!s[i])
            break;
        sp_count += 1;
        skip_spaces_ncount(s, &i, &sp_total);
    }
    int s_size = i;
    int fin_size = s_size - sp_total + sp_count;
    char *fin = mx_strnew(fin_size);
    int j = 0;
    i = 0;

    for (j = 0; j < fin_size; j++)
    {
        fin[j] = s[i];
        if (mx_isspace(s[i]))
        {
            skip_spaces(s, &i);
            continue;
        }
        i++;
    }
    free((void *)s);
    return fin;
}

