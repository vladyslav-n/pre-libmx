#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <unistd.h>
//#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#define DEBUG

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
bool mx_isdigit(int c);
char *mx_nbr_to_hex(unsigned long nbr);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_strcmp(const char *s1, const char *s2);
int mx_quicksort(char **arr, int left, int right);






















