#pragma once
#include "../libmx/inc/libmx.h"
#define GRID_INIT_VAL -1

enum errors {
    INV_ARGC,
    FILE_NOT_EXIST,
    FILE_EMPTY,
    INV_FIRST_LINE,
    INV_LINE,
    INV_NUM_OF_ISLS
};

typedef struct s_route {
    int len;
    int *route_isls;
    int total_dist;
} t_route;

// typedef struct s_all_pathes {
//     int count;
//     t_route *route;
// } t_all_pathes;

typedef struct s_routes_list {
    int count;
    t_route *arr_routes;
} t_routes_list;



// typedef struct s_shortest_pathes {
//     int count;
//     t_route **routes;
// } t_shortest_pathes;

char **mx_strsplit_ncount(const char *s, char c, int *count);
int skip_untilchar_ncount(const char *str, char c, int *i);

