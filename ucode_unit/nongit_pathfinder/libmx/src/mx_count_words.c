#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void skipchar(const char *str, char c, int *i)
{
    for (; str[*i] == c; (*i)++) {}
}
void skip_untilchar(const char *str, char c, int *i)
{
    for (; str[*i] != c && str[*i]; (*i)++) {}
}

int mx_count_words(const char *str, char c)
{
    if (!str)
        return -1;
    if (!str[0])
        return 0;
    int i = 0;
    int count = 0;
    skipchar(str, c, &i);
    while (str[i])
    {
        skip_untilchar(str, c, &i);
        skipchar(str, c, &i);
        count += 1;
    }
    return count;
}

