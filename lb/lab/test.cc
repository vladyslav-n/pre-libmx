#include "../inc/libmx.h"
#include <stdio.h>

int eoferrno_test()
{
    for (int i = 0; i < 10; i++)
    {
        if (i++ == 2)
        {
            return --i;

        }
        printf("%d\n", i);
    }
    return 1;
}

