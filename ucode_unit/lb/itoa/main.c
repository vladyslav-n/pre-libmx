#include "../inc/libmx.h"

int main()
{   
    printf("%s\n", mx_itoa(-2147483648));
    printf("%s\n", mx_itoa(2147483647));
    char *str = mx_itoa(52); //returns "34"
    char *str1 = mx_itoa(1000); //returns "3e8"
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%s\n", mx_itoa(256));
    printf("%s\n", mx_itoa(1024));
    printf("%s\n", mx_itoa(-65535));
    printf("%s\n", mx_itoa(0));
    mx_itoa(52);
    mx_itoa(1000);
}

