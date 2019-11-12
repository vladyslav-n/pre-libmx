#include "../inc/libmx.h"
#include <stdio.h>
int eoferrno_test();


int main() {
    char *ptr = calloc(5, 1);
    printf("memory before = %d\n", (int)ptr);

    printf("memory after = %d\n", (int)(ptr = realloc(ptr, 7)));
}

