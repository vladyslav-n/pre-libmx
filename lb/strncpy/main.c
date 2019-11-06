#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    const char src[] = "000";
    char dst[] = "123456";
    const char src1[] = "000";
    char dst1[] = "123456";
    const char src2[] = "000";
    char dst2[] = "123456";
    const char src3[] = "000";
    char dst3[] = "123456";
    
    mx_strncpy(dst, src, 3);
    mx_strncpy(dst1, src1, 4);
    mx_strncpy(dst2, src2, 5);
    mx_strncpy(dst3, src3, 2);
}


