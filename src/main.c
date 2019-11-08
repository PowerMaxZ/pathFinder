#include "pathFinder.h"

static void mx_sort_lists(t_list *list);
static bool mx_lengthcmp(void *s1, void *s2);
static void mx_print_shortest_path(t_list *all_paths, int *matrix, int count_islands, char **islands);

int main(int argc, char **argv) {
    char **arr_islands = NULL;
    char *text_of_file = NULL;
    int islands_count = 0;
    int *matrix;

    if (argc != 2) {
        mx_printerr(INVLD_CMD_ARGS, NULL);
    }
    text_of_file = mx_file_to_str(*(argv + 1));
    mx_check_text(text_of_file);
    arr_islands = mx_check_text_value(text_of_file);
    matrix = mx_get_matrix(arr_islands, text_of_file);
    islands_count = mx_arr_size(arr_islands);
    t_graph *graph = mx_get_graph_matrix(matrix, islands_count);
    t_list *all_paths = mx_create_node(".");

    for (int i = 0; i < islands_count; i++) {
        for (int j = 0; j < islands_count; j++) {
            mx_push_back(&all_paths, mx_get_path_bt_islands(graph, i, j, islands_count));
        }
    }
    mx_sort_lists(all_paths);
    mx_print_shortest_path(all_paths, matrix, islands_count, arr_islands);
}

static void mx_print_shortest_path(t_list *all_paths, int *matrix, int count_islands, char **islands) {
    t_list *current = all_paths->next;
    t_list *printed_paths = mx_create_node(".");
    t_list *printed_reverse_paths = mx_create_node(".");

    while (current) {
        int min_path = 2000000000;
        t_list *tmp_current = ((t_list *)current->data)->next;

        while (tmp_current) {
            int current_path = mx_get_weight_path(tmp_current->data, matrix, count_islands);
            if (current_path < min_path) {
                min_path = current_path;
            }
            tmp_current = tmp_current->next;
        }
        tmp_current = ((t_list *)current->data)->next;
        char *last_data = ".";
        bool is_printed = false;
        while (tmp_current) {
            int current_path = mx_get_weight_path(tmp_current->data, matrix, count_islands);
            
            t_list *tmp_reversed = printed_reverse_paths;
            t_list *tmp_printed = printed_paths;
            while (tmp_reversed && tmp_printed) {
                if (!mx_strcmp(tmp_reversed->data, tmp_current->data) ||
                    !mx_strcmp(tmp_printed->data, tmp_current->data)) {
                    is_printed = true;
                }
                tmp_reversed = tmp_reversed->next;
                tmp_printed = tmp_printed->next;
            }

            if (current_path == min_path && !is_printed) {
                char *tmp_reversed_str = mx_strdup(tmp_current->data);
                mx_str_reverse(tmp_reversed_str);
                mx_push_back(&printed_reverse_paths, tmp_reversed_str); 
                mx_push_back(&printed_paths, tmp_current->data);
                mx_print_path(tmp_current->data, islands, count_islands, matrix, current_path);
            }
            is_printed = false;
            last_data = tmp_current->data;
            tmp_current = tmp_current->next;
        }
        current = current->next;
    }
}

static void mx_sort_lists(t_list *list) {
    t_list *tmp = list->next;

    while (tmp) {
        tmp->data = mx_sort_list(((t_list *)tmp->data), mx_lengthcmp);
        tmp = tmp->next;
    }
}
 
static bool mx_lengthcmp(void *s1, void *s2) {
    char *str1 = (char *)s1;
    char *str2 = (char *)s2;
    int length_str1 = mx_strlen(str1);
    int length_str2 = mx_strlen(str2);

    if (length_str1 > length_str2) {
        return true;
    }
    else if (length_str1 == length_str2) {
        int diff = mx_strcmp(str1, str2);
        if (diff > 0) {
            return true; 
        }
    }
    return false;
}
