#include "../inc/header.h"
#include <stdio.h>
// #define DEBUG
// #define DEBUGG

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
    return i * (2 * n - 3 - i) / 2 + j - 1;
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
    if (!n) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        if (!used_isl[i]) {
            return i;
        }
    }
    return -1;
}

// int **create_arr_routes_list(int num) {
//     t_list **arr_routes_list = (t_list**) malloc 
//         (num * sizeof(t_list*));
//     for (int i = 0; i < num; i++) {
//         arr_routes_list[i] = NULL;
//     }
//     return arr_routes_list;
// }

int route_dist(t_list *cur_route, int len, int **grid) {
    int dist = 0;
    for (int i = 0; i < len - 1; i++)
    {
        dist += grid[*((int*)(cur_route->data))]
                    [*((int*)(cur_route->next->data))];
        cur_route = cur_route->next;
    }
    return dist;
}

int *create_root(t_list *route, int len, int **grid) {
    int *new_route = (int*)malloc(sizeof(int) * (len + 2));
    int dist = 0;
    int i = 2;
    for (i = 0; i < len - 1; i++)
    {
        dist += grid[*((int*)(route->data))]
                    [*((int*)(route->next->data))];
        new_route[len + 1 - i] = *((int*)(route->data));
        route = route->next;
    }
    new_route[2] = *((int*)(route->data));
    new_route[0] = dist;
    new_route[1] = len;
    return new_route;
}

void mx_clear_list_routs(t_list **head) {
    if (!*head || !head) {
        return;
    }
    while (*head) {
        free((*head)->data);
        mx_pop_front(head);
    }
}



void print_distance(int *route, int **grid) {
    int i = 0;
    mx_printstr("Distance: ");
        for (i = 0; i < route[1] - 2; i++)
        {
            mx_printint(grid[route[i + 2]][route[i + 3]]);
            mx_printstr(" + ");
        }

            if (route[1] > 2)
            {
                mx_printint(grid[route[i + 2]][route[i + 3]]);
                mx_printstr(" = ");
            }
        mx_printint(route[0]);
        mx_printstr("\n");
}

void print_route(int *route, char **names) {
    int i = 0;

    mx_printstr("Route: ");
    for (i = 0; i < route[1] - 1; i++)
    {
        mx_printstr(names[route[i + 2]]);
        mx_printstr(" -> ");
    }
        mx_printstr(names[route[i + 2]]);
        mx_printstr("\n");
}

void print_path(t_list *pathes, char **names, int **grid) {
    // int path_ind = RI(i, j, n);
    int len = -1;

    while (pathes) 
    {
        len = *((int*)(pathes->data) + 1);
        mx_printstr("========================================\nPath: ");
        mx_printstr(names[*((int*)(pathes->data) + 2)]);
        mx_printstr(" -> ");
        mx_printstr(names[*((int*)(pathes->data) + len + 1)]);
        mx_printstr("\n");
        print_route(pathes->data, names);
        print_distance(pathes->data, grid);
        mx_printstr("========================================\n");
        pathes = pathes->next;
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
    argc++;
    argc--;
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
    // int start = -1;
    int *used_isl = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        used_isl[i] = -1;
    }

    int *isl_nums = (int*) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        isl_nums[i] = i;
    }
    
    for (int i = 0; i < n - 1; i++) { 
        
        t_list *cur_route = mx_create_node(&isl_nums[i]);
        init_used_isl_arr(used_isl, n, i);
        // t_list *start_isl = cur_route;
        int cur_route_len = 1;
        int cur_i = i;
        int j = -1;
        int prev_isl = -1;
        char flag = 0;
        while(cur_route)
        {

            while((j = choose_isl(used_isl + prev_isl + 1, 
                    n - prev_isl - 1)) >= 0) {
                j += prev_isl + 1;
                                #ifdef DEBUG
                                printf("Beginning of 1-st WHILE. i = %d j = %d, cur_i = %d, prev_isl = %d, cur_route_len = %d\n", i, j, cur_i, prev_isl, cur_route_len);
                                
                                #endif 
                
                while (grid[cur_i][j] < 0 || used_isl[j]) {   
                    if (++j == n) {
                        break;
                    }
                }
                if (j == n) 
                {
                    // prev_isl = n - 1;
                    flag = 1;  //flag means we have unused isls but have no bridges to them
                                #ifdef DEBUG
                                printf("Breaking from the 1-st WHILE. i = %d j = %d, cur_i = %d, prev_isl = %d, cur_route_len = %d\n", i, j, cur_i, prev_isl, cur_route_len);
                                #endif 
                    break;
                }
                mx_push_front(&cur_route, &isl_nums[j]);
                cur_route_len += 1;
                cur_i = *((int*)(cur_route->data));
                used_isl[cur_i] = 1;
                prev_isl = -1;
                                #ifdef DEBUG
                                printf("The ending of 1-st WHILE. i = %d j = %d, cur_i = %d, prev_isl = %d, cur_route_len = %d\n", i, j, cur_i, prev_isl, cur_route_len);
                                for (int i = 0; i < n; i++) {
                                    if (used_isl[i]){
                                        printf("%d ", i);
                                    }
                                }
                                        printf("\n");
                                #endif 

            }
            while((j = choose_isl(used_isl + (prev_isl + 1), 
                    n - prev_isl - 1)) < 0 || flag) {
                j += prev_isl + 1;
                                #ifdef DEBUG
                                printf("BEG 2-nd WHILE. i = %d j = %d, cur_i = %d, prev_isl = %d, cur_route_len = %d\n", i, j, cur_i, prev_isl, cur_route_len);
                                #endif 
                flag = 0;
                if (cur_i > i) 
                {
                    int ri_tmp = RI(i, cur_i, n);

                    if (!shortest_path[ri_tmp]) {
                        mx_push_back(&shortest_path[ri_tmp], 
                        create_root(cur_route, cur_route_len, grid));
                    }
                    else if (*((int*)(shortest_path[ri_tmp]->data))
                          == route_dist(cur_route, cur_route_len, grid)) {
                        mx_push_back(&shortest_path[ri_tmp], 
                        create_root(cur_route, cur_route_len, grid));
                    }
                    else if (*((int*)(shortest_path[ri_tmp]->data))
                          > route_dist(cur_route, cur_route_len, grid)) 
                    {
                        mx_clear_list_routs(&shortest_path[ri_tmp]);
                        mx_push_back(&shortest_path[ri_tmp], 
                        create_root(cur_route, cur_route_len, grid));
                    }
                }
                used_isl[cur_i] = 0;
                prev_isl = cur_i;
                mx_pop_front(&cur_route);
                if (cur_route) {
                    cur_i = *((int*)(cur_route->data));
                }
                cur_route_len -= 1;
                                #ifdef DEBUG
                                printf("end 2-nd WHILE. i = %d j = %d, cur_i = %d, prev_isl = %d, cur_route_len = %d\n", i, j, cur_i, prev_isl, cur_route_len);
                                for (int i = 0; i < n; i++) {
                                    if (used_isl[i]){
                                        printf("%d ", i);
                                    }
                                }
                                        printf("\n");

                                #endif 

            }
                                #ifdef DEBUG
                                printf("\nEnd of main WHILE.\n\n");
                                #endif 

        }
    }

    if (1 > 2) {  //DELETETETETETETTETETE!!!!!!!!!!!!!!!!!!
        argc++;
        argc--;
    }



    /* printing */
    for (int i = 0; i < routes_count; i++) {
        print_path(shortest_path[i], isl_names, grid);
    }
    
}

