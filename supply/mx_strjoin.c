#include <stdlib.h>

char *mx_strjoin(char const *s1, char const *s2)
{
    if (size >= 0)
    {
        char *str = (char*) malloc(size + 1);
        if (NULL == str)
            return NULL; 
        else
            for (int i = 0; i <= size; i++) 
                str[i] = '\0';
        return str;
    }
    else return NULL;
}
