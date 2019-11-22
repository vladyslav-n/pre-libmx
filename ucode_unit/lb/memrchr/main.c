#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    const void *ptr = "Trinity";
    printf("%s\n", mx_memrchr(ptr, 'M', 7));
    printf("%s\n", ptr);

}

