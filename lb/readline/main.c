#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    int fd = open("copy", O_RDONLY);
    char *s = (char*) calloc(1000, 1);
    int sum = 0;
    char *reserv = s;
    int read_bytes = 0, buf_size = 100;
    while ((read_bytes = mx_read_line(&s, buf_size, ' ', fd)) > 0)
    {
        sum += read_bytes;
#ifdef DEBUG
    printf("read chars = %d\n", read_bytes);
#endif
    }
//     read_bytes = mx_read_line(&s, buf_size, '*', fd);
//         sum += read_bytes;
// #ifdef DEBUG
// printf("Succsess\n");
//     printf("read chars = %d\n", sum);
//     printf("%s\n", reserv);

// #endif


    
    printf("sum = %d\n", sum);
    printf("%s\n", reserv);
    close(fd);
    //free(s);
}

