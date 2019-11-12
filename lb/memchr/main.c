#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    const void *ptr = "Trinity";
    printf("%s\n", mx_memchr(ptr, 'n', 7));
    printf("%s\n", ptr);

}

