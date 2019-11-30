#include "inc/libmx.h"
#include <stdio.h>
#include <string.h>

int main(int ac, char **av) {

	// char name[] = "\f  My name...     is  \r Neo  \t\n ";
	// char *str = mx_del_extra_spaces(name);
	// printf("%s\n", str); //returns "My name... is Neo"
	// while(1) {

	// }
//*********************************************************************************mx_del_extra_spaces

   // char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael", NULL};
   // mx_print_strarr(arr, "\n**********\n");

//*********************************************************************************mx_print_strarr


	// unsigned char src[10] = "123456";
 // 	unsigned char dst[10]= "";

	// mx_memcpy(dst, src, 6);
	// printf("dst: %s\n" , dst);
//************************************************************************************mx_memcpy

   // unsigned char src[15]= "1234567890";

   // unsigned char dst[15]= "";

   // printf ("dst: %s\n", mx_memccpy(dst, src, '5', 10));
 
//************************************************************************************mx_memcmp

	// unsigned char src[15] = "1234567890";
	// unsigned char dst[15] = "123456789"; 
	
	// printf("n = %d", mx_memcmp(src, dst, 9));

	// printf("res = %s\n", mx_memrchr("Trinity", 'i', 7));
	// printf("res = %s\n", mx_memrchr("Trinity", 'M', 7));
	// return 0;

//*************************************************************************************mx_memrchr


   // char str1[11]= "0123456789";
   // char str2[10]= "345";
   // char *istr;

//**************************************************************************************mx_strstr

   // istr = mx_strstr(str1,str2);

   // if (istr == NULL)
   //    printf ("NULL");
   // else
   //    printf ("res = %ld\n",istr - str1 + 1);

   // return 0;


//**************************************************************************************mx_memmem


 //    char str1[11]= "0123456789";
 //    char str2[10]= "456";

// printf("res = %s\n", mx_memmem(str1, 3, str2, 2));


//*************************************************************************************mx_quicksort


  int count;
  char *arr[] = {"Raphael1", "Raphael2", "Leonardo2", "Leonardo1", "Donatello2", "Donatello1", "Michelangelo1", "Michelangelo2"};
  int i = -1;
  
  while (++i < 8)
  {
    printf("%s\n", arr[i]);
  }
  count = mx_quicksort(arr, 0, 7);
  printf("\n******************\n");
  i = -1;
  while (++i < 8)
  {
    printf("%s\n", arr[i]);
  }
  printf("count = %d\n", count);
  return 0;
 
 //**************************************************************************************mx_count_substr

 // char *str = "yo, yo, yo yoyoyoNeo";
 // char *sub = "yo";

 // printf("return %d\n", mx_count_substr(str, sub)); //eturns 3
 // printf("return %d\n", mx_count_substr(str, NULL)); //returns -1
 // printf("return %d\n", mx_count_substr(NULL, sub)); //returns -1
 
//********************************************************************************************mx_realoc

     
// char *ptr;
// ptr = mx_realloc(NULL, 20*sizeof(char));
// mx_strcpy(ptr, "Это первая часть, ");
// printf("%s\n", ptr);
// printf("%zu\n", malloc_size(ptr));
// ptr = mx_realloc(ptr, 1 * sizeof(char));
// //mx_strcat(ptr, "Это вторая часть");
// printf("%s\n", ptr);
// printf("%zu\n", malloc_size(ptr));
// mx_realloc(ptr, 0);

//**********************************************************************************************mx_strsplit.c
    
      //    char s1[] = "  ";
      //    char **arr1 = mx_strsplit(s1, ' ');
      //   // //char **arr2 = mx_strsplit(av[1], av[2][0]);
      //   int i = 0;
      //    while (arr1[i]) 
      //    printf("%s\n", arr1[i++]);
     

//
//

//***********************************************************************************************


//   char s[] = "         123456789**";
//   printf("%d\n", count_letters(s, '3'));

//********************************************************************************************************mx_replace_sub_str


// char str[] = "McDonalds";
// char sub[] = "alds";
// char rep[] = "uts";
// char *str2;
// printf("str = %s\n", str2 = mx_replace_substr(str, sub, rep)); //returns "McDonuts"

//********************************************************************************************************HARDTEST quicksort
// int size = 40;
// char **arr = (char **)malloc(sizeof(char *) * size);
//     for (int i = 0; i < size; ++i) {
//         arr[i] = mx_strnew(99);
//         for (int j = 0; j < rand() % 100; ++j)
//             for (int k = 0; k < j; ++k)
//                 arr[i][k] = 65 + rand() % 26;
//     }

//     int j = mx_quicksort(arr, 0, size - 1);
//     printf("Sorted array:\n");
//     for(int i = 0; i < size; ++i)
//         printf(":%s:\n", arr[i]);
//     printf("%d\n", j);

//****************************************************************************************************mx_file_to_str

  // printf("str= %s", mx_file_to_str(av[1]));
  // while(1);

//*****************************************************************************************************mx_read_line


//      char s[] = "aaaa";
//     char s1[] = "bbbbb";
//     char s2[] = "cccccc";
//     char s3[] = "ddddddd";
//     char s4[] = "eeeeeeee";
//     char s5[] = "fffffffff";
//     char s6[] = "gggggggggg";

//     t_list *list = mx_create_node(s);

//     mx_push_front(&list, s1);
//     mx_push_front(&list, s5);
//     mx_push_front(&list, s3);
//     mx_push_front(&list, s2);
//     mx_push_front(&list, s6);
//     mx_push_front(&list, s4);
//     mx_sort_list(list, cmp);
//     while (list != NULL) {
//         printf("%s ",  list->data);
//         list = list->next;
//     }
// t_list *list =  NULL;
// mx_push_back(&list, "First");
// mx_push_back(&list, "Second");
// mx_push_back(&list, "Third");
// mx_pop_front(&list);
// while (list) {
//       printf("%s\n", list->data);
//       list = list->next;
//}
//************************************************************************************************************mx_print_unicode

   //wchar_t c = 0x1F646;
   //mx_print_unicode(c);

  //*****************************************************************************************************************mx_itoa

// printf("str = %s", atoi(mx_itoa(av[1])));
// char s1[] = "aaaaabb aaaaa";
// char s2[] = "bb";
//printf("%s\n",mx_strstr(s1, s2));
 system("leaks -q a.out");       
      return 0;

}

