#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c)
{
    if (c < 128)
    {
        write(1, c, 1);
        return;
    }
    if (c < 2048)
    {
        
    }
    char wbuff = (char) &c;
    write(1, wbuff, sizeof(wchar_t));
}

