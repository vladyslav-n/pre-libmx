#include "../inc/libmx.h"
#include <stdio.h>
#include <string.h>

void foo()
{
    static t_tail tail;
    printf("s = %s\n", tail.s);
    printf("len = %d\n", tail.len);
    tail.s = strdup("word");
    tail.len = strlen(tail.s);
}


int main() {
    foo();
    foo();
}

