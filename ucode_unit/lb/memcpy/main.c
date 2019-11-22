#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    void *ptr = strdup("____--");
    const void *ptr1 = strdup("Trinity");
    printf("%s\n", mx_memcpy(ptr, ptr1, 9));

}

