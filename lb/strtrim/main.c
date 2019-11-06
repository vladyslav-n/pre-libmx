#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    const char *name = "\f  My name... is Neo  \t\n ";
    printf("%s\n", name);
    printf("%s\n", mx_strtrim(name)); //returns "My name... is Neo"
}

