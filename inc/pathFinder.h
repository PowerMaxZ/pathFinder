#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <malloc/malloc.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>

#include "libmx/inc/libmx.h"

typedef enum e_error {
    INVLD_CMD_ARGS,
    FILE_DEXST,
    FILE_EMPTY,
    INVLD_FRST_LINE,
    INVLD_LINE,
    INVLD_NUM_ISLDS
} t_error;

typedef struct s_adj_list_node {
    int dest;
    struct s_adj_list_node *next;
} t_adj_list_node;

typedef struct s_adj_list {
    struct s_adj_list_node *head;
} t_adj_list;

typedef struct s_graph {
    int V;
    struct s_adj_list *array;
} t_graph;

t_adj_list_node *mx_new_adj_list_node(int dest);
t_graph *mx_create_graph(int V);
void mx_add_edge(t_graph *graph, int src, int dst);
void mx_print_graph(t_graph *graph);

void mx_printerr(t_error err, const char *comment);
void mx_printerror(const char *error);
int mx_numlen(int num);
bool mx_check_text(char *text);
bool mx_isnum(const char *str);
bool mx_isword(const char *str);
bool mx_isletter (char c);
char **mx_check_text_value(char *text);
int mx_arr_size(char **arr);
int *mx_get_matrix(char **islands, char *text_of_file);
int mx_get_length_bt_isl(int *matrix, char **islands, char *i1, char *i2);
int mx_get_index_island(char **islands, char *island);
int *mx_get_paths(int *matrix, char **islands);
t_list *mx_get_path_bt_islands(t_graph *graph, int i1, int i2, int count_islands);

t_list  *mx_create_node(void *data);
t_graph *mx_get_graph_matrix(int *matrix, int count_islands);
int mx_get_weight_path(char *path, int *matrix, int count_islands);
void mx_print_path(char *str_path, char **islands, int count_islands, int *matrix, int distance);
int mx_ctoi(char c);
char *mx_itoa(int number);
bool mx_isdigit(char c);
char *mx_file_to_str(const char *file);
int mx_atoi(const char *s);

#endif
