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
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
        // else if (i == isl_index) {
        //     arr[i] = 1;
        // }
    }
    arr[isl_index] = 1;
}

int choose_isl(int *used_isl, int n) {
    if (0 == n) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (!used_isl[i]) {
            return i;
        }
    }
    return -1;
}

t_routes_list* create_arr_routes_list(int num) {
    t_routes_list* arr_routes_list = (t_routes_list*) malloc 
        (num * sizeof(t_routes_list));
    for (int i = 0; i < num; i++)
    {
        arr_routes_list[i].arr_routes = NULL;
        arr_routes_list[i].count = 0;
    }
    return arr_routes_list;
}

int route_dist(t_list *cur_route, int len, int **grid) {
    int dist = 0;
    for (int i = 0; i < len - 1; i++)
    {
        dist += grid[*((int*)(cur_route->data))]
                    [*((int*)(cur_route->next->data))];
        cur_route = cur_route->next;
    }
    
    
}

void save_route(t_list *cur_route, int cur_route_len, 
    t_routes_list* arr_routes_list, int root_index) {

    if (!arr_routes_list[root_index].count) {
        save_route(cur_route, cur_route_len, RI(i, j, n));
    }
    else if (arr_routes_list[RI(i, cur_i, n)].arr_routes[0].total_dist 
        >= route_dist(cur_route, cur_route_len, grid)) {
        save_route(cur_route, cur_route_len, 
            arr_routes_list, RI(i, j, n));
    } 
}

int main(int argc, char *argv[]) {

    // open(argv[1], O_RDONLY);
    /* save file to str */
    char *file = mx_file_to_str(argv[1]);
    int lines_count = 0;

    /* devide file into separate lines & save the islands quantity */
    char **file_lines = mx_strsplit_ncount(file, '\n', &lines_count);
    int isl_count = mx_atoi(file_lines[0]);

    /* creating an array of lines, splitted into words */
    char ***extra_isl_names
         = (char***) malloc((lines_count - 1) * sizeof(char**));
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
    

    /* creating all the routes from i-th islands to j-th (MAIN ALGORYTHM) */
    int start = -1;
    int *used_isl = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        used_isl[i] = -1;
    }
    
    t_routes_list *arr_routes_list = 
        create_arr_routes_list (n * (n - 1) / 2);

    for (int i = 0; i < n - 1; i++) { 
        
        t_list *cur_route = mx_create_node(grid[i]);
        init_used_isl_arr(used_isl, n, i);
        // t_list *start_isl = cur_route;
        int cur_route_len = 1;
        int cur_i = i;
        int j = -1;
        int prev_isl = -1;
        while(cur_route)
        {
            while((j = choose_isl(used_isl + (prev_isl + 1) * sizeof(int), n - prev_isl - 1)) >= 0) //WARNING!!!!! NEED TO BE CORRECTED
            //BUG - when NOT ALL the islands were used
            //BUG - prev isl when starting from beg.
            {
                
                while (grid[cur_i][j] < 0) 
                {   //WARNING!!!!! NEED TO BE CORRECTED       
                    if (++j == n) {
                        break;
                    }
                }
                if (j == n) {
                    prev_isl = n - 1;
                    break;
                }
                mx_push_front(&cur_route, grid[j]);
                cur_route_len += 1;
            
                // start_isl = start_isl->next;
                used_isl[j] = 1;
                cur_i = j;
                prev_isl = -1;
            }
            while((j = choose_isl(used_isl + (prev_isl + 1) * sizeof(int), 
                    n - prev_isl - 1)) < 0) {
                // if (*((int*)(cur_route->data)) > i) {
                //     save_route(cur_route, cur_route_len);
                // }
                if (cur_i > i) {
                    if (!arr_routes_list[RI(i, cur_i, n)].count) {
                        save_route(cur_route, cur_route_len, RI(i, j, n));
                    }
                    else if (arr_routes_list[RI(i, cur_i, n)].arr_routes[0].total_dist 
                        >= route_dist(cur_route, cur_route_len, grid)) {
                        save_route(cur_route, cur_route_len, 
                            arr_routes_list, RI(i, j, n));
                    }
                }
                used_isl[cur_i] = 0;
                prev_isl = cur_i;
                mx_pop_front(cur_route);
                if (cur_route) {
                    cur_i = *((int*)(cur_route->data));
                }
                cur_route_len -= 1;
            }

        }
    }

    // /* searching for a route from i-th island to j-th */

}

