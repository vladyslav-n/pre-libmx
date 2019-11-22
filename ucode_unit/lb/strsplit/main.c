#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    // const char *s = "**Good bye,**Mr.*Anderson.****";
    // char **arr = mx_strsplit(s, '*');  // arr = ["Good bye,", "Mr.", "Anderson."]
    const char *s = "KSf#WV7cmJ7FCmCYpT3CCjp8J3w9RXnh7UCdY0mRda6Q0jTA#D2BRxggDkUSPecHyhHyWbekEj6pvzg1hozb98WSwoEapAz VKSe5KPE9uA#SKi#U7p";
    char **arr = mx_strsplit(s, '#');  // arr = ["Knock,", "knock,", "Neo."]
    mx_print_strarr(arr, "\n");
}

