#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
char *str = "   ";
printf("%d\n", mx_count_words(str, '*')); //returns 2
printf("%d\n", mx_count_words(str, ' ')); //returns 5
printf("%d\n", mx_count_words(NULL, ' ')); //returns -1

}

