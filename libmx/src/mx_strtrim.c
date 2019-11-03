#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void skip_spaces(const char *str, int *i)
{
    for (; mx_isspace(str[*i]); (*i)++) {}
}
void skip_untilspace(const char *str, int *i)
{
    for (; !mx_isspace(str[*i]) && str[*i]; (*i)++) {}
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
    return mx_strndup(str + min_index, nul_index - min_index);
}

