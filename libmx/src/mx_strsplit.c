#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

int skip_untilchar_ncount(const char *str, char c, int *i)
{
    int count = 0;
    for (; str[*i] != c && str[*i]; (*i)++)
        count += 1;
    return count;
}

char **mx_strsplit(const char *s, char c)
{
    if (!s)
        return NULL;
    int words_count = mx_count_words(s, c);
    char **arr = (char**) malloc(sizeof(char*) * (words_count + 1));
    arr[words_count] = NULL;
    int word_len = 0;
    int i = 0;
    int j = 0;
    //skipchar(s, c, &i);
    while (s[i])
    {
        if ((word_len = skip_untilchar_ncount(s, c, &i)))
        {
            arr[j] = mx_strndup(s + i - word_len, word_len);
            j++;
        }
        skipchar(s, c, &i);
    }
    return arr;
}

