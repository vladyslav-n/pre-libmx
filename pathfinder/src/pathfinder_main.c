#include "../inc/header.h"
#include <stdio.h>
#define DEBUG

int **create_grid(int row, int col, int val)
{
    int i, j = 0;

    int **arr = (int **)malloc(row * sizeof(int *)); 
    for (i = 0; i < row; i++) 
         arr[i] = (int *)malloc(col * sizeof(int)); 
  
    // Note that arr[i][j] is same as *(*(arr+i)+j) 
    for (i = 0; i <  row; i++) 
      for (j = 0; j < col; j++) 
        arr[i][j] = val;
    return arr;
}

char **create_list_of_names(int count, const char *s)
{
    char **names = (char**) malloc((count + 1) * sizeof(char*));
    names[count] = NULL;
    for (int i = 0; i < count; i++) {
        names[i] = (char*)s;
    }
    return names;
}

int word_index(char **arr, char *word)
{
    for (int i = 0; arr[i]; i++) 
    {
        if (!mx_strcmp(arr[i], word))
            return i;
    }
    return -1;
}

void printerror(int num)
{  
    switch (num) 
    {
        case INV_NUM_OF_ISLS:
            mx_printerror("error: invalid number of islands\n");
            break;
    }
    exit(num);
}

/* root number index */
int RI(int i, int j, int n) {
    return (i * (2 * n - 3 - i)) / 2 + j - 1;
}

void init_used_isl_arr(int *arr, int len, int isl_index) {
    for (int i = 0; i < len; i++)
    {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
        else if (i == isl_index) {
            arr[i] = 1;
        }
    }
    
}

int main(int argc, char *argv[])
{
    // open(argv[1], O_RDONLY);
    /* save file to str */
    char *file = mx_file_to_str(argv[1]);
    int lines_count = 0;

    /* devide file into separate lines & save the islands quantity */
    char **file_lines = mx_strsplit_ncount(file, '\n', &lines_count);
    int isl_count = mx_atoi(file_lines[0]);

    /* creating an array of lines, splitted into words */
    char ***extra_isl_names = (char***) malloc((lines_count - 1) * sizeof(char**));
    for (int i = 0; i < lines_count - 1; i++) {
        extra_isl_names[i] = mx_strsplit(file_lines[i + 1], '-');
    }
    for (int i = 0; i < lines_count - 1; i++) {
        extra_isl_names[i][1][mx_get_char_index(extra_isl_names[i][1], ',')]
            = 0;
    }

    /* creating an array of distances between islands */
    int **grid = create_grid(isl_count, isl_count, GRID_INIT_VAL);

    /* creating an array of islands' names and filling the grid */
    char **isl_names = create_list_of_names(isl_count, "");
    int count = 0;
    int wi1, wi2 = -2;
    // int names_in_file_count = 0;
    for (int i = 0; i < lines_count - 1; i++)
    {
        if ((wi1 = word_index(isl_names, extra_isl_names[i][0])) < 0) {
            if (count == isl_count) {
                printerror(INV_NUM_OF_ISLS);
            }
            isl_names[count] = mx_strdup(extra_isl_names[i][0]);
            wi1 = count++;
        }
        if ((wi2 = word_index(isl_names, extra_isl_names[i][1])) < 0) {
            if (count == isl_count) {
                printerror(INV_NUM_OF_ISLS);
            }
            isl_names[count] = mx_strdup(extra_isl_names[i][1]);
            wi2 = count++;
        }
        grid[wi1][wi2] = mx_atoi(extra_isl_names[i][1] 
            + mx_strlen(extra_isl_names[i][1]) + 1);
        grid[wi2][wi1] = grid[wi1][wi2];
    }
    if (count < isl_count) {
        printerror(INV_NUM_OF_ISLS);
    }
#ifdef DEBUG
mx_print_strarr(isl_names, "\n");
printf("\nand the grid:\n");
for (int i = 0; i < isl_count; i++)
{
      for (int j = 0; j < isl_count; j++) 
         printf("%d ", grid[i][j]); 
    printf("\n");
}
    // argc++;
    // argc--;
#endif 

    /* creating an array of lists of the shortest routes 
     * (they may be not unique)
     */
    int n = isl_count;
    int routes_count = (n * (n - 1)) / 2;

    t_list **shortest_path
         = (t_list**)malloc(sizeof(t_list*) * routes_count);
    for (int i = 0; i < routes_count; i++) {
        shortest_path[i] = NULL;
    }
    

    /* creating all the routes from i-th islands to j-th */
    int start = -1;
    int *used_isl = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        used_isl[i] = -1;
    }
    
    for (int i = 0; i < n - 1; i++) { 
        for (int j = i + 1; j < n; j++)
        {
            if (grid[i][j] > 0)
            start = j;
        }
        
    }

    // /* searching for a route from i-th island to j-th */

}

