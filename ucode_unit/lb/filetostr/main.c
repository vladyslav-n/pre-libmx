#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main(int argc, char *argv[])
{
    //mx_file_to_str(argv[1]);
    printf("%s\n", mx_file_to_str(argv[1]));
    argc++;
}

