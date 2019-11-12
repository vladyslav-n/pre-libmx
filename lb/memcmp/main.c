#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    // const void *ptr = "Trinity";
    // const void *ptr1 = "Trinity";
    printf("%d\n", mx_memcmp("", "Trinity1", 8));

}

