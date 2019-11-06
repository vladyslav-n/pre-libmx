#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif

void mx_strdel(char **str)
{
    free(*str);
    *str = NULL;
}

