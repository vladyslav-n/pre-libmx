#include "../inc/libmx.h"

int main()
{
    char *str = mx_nbr_to_hex(52); //returns "34"
    char *str1 = mx_nbr_to_hex(1000); //returns "3e8"
    printf("%s\n", str);
    printf("%s\n", str1);
    printf("%s\n", mx_nbr_to_hex(256));
    printf("%s\n", mx_nbr_to_hex(1024));
    printf("%s\n", mx_nbr_to_hex(65535));
    printf("%s\n", mx_nbr_to_hex(0));
    
}

