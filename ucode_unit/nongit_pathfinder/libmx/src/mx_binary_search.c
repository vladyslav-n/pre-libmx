#include <stdlib.h>
int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    *count = 0;
    if (size < 1 || !s || !arr || !count)
        return -1;
    int bot = 0;
    int up = size - 1;
    int mid = (bot + up) / 2;
    
    while (mx_strcmp(s, arr[mid]) && bot != up) {
        if (mx_strcmp(s, arr[mid]) > 0)
        {
            bot = mid + 1;
            mid = (bot + up) / 2;
        }
        else
        {
            up = mid - 1;
            mid = (bot + up) / 2;
        }
        *count  += 1;
    }
    if (!mx_strcmp(s, arr[mid])) 
    {
        *count  += 1;
        return mid;
    }
    else
        *count = 0;
        return -1;
}

