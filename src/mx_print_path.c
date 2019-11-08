#include "pathFinder.h"

static void mx_print_boundary();
static void mx_print_current_path(char *str_path, char **islands);
static void mx_print_route(char *str_path, char **islands);
static void mx_print_distance(char *str_path, int *matrix, int distance, int count_islands);

void mx_print_path(char *str_path, char **islands, int count_islands, int *matrix, int distance) {
    mx_print_boundary();
    mx_print_current_path(str_path, islands);
    mx_print_route(str_path, islands);
    mx_print_distance(str_path, matrix, distance, count_islands);
    mx_print_boundary();
}

static void mx_print_distance(char *str_path, int *matrix, int distance, int count_islands) {
    mx_printstr("Distance: ");
    if (mx_strlen(str_path) == 2) {
        mx_printstr(mx_itoa(distance));
    }
    else {
        for (int i = 0; i < mx_strlen(str_path) - 1; i++) {
            int weight = *(matrix + mx_ctoi(str_path[i]) * count_islands + mx_ctoi(str_path[i + 1]));
            mx_printstr(mx_itoa(weight));
            if (str_path[i + 2]) {
                mx_printstr(" + ");
            }
        }
        mx_printstr(" = ");
        mx_printstr(mx_itoa(distance));
    }
    mx_printstr("\n");
}

static void mx_print_route(char *str_path, char **islands) {
    mx_printstr("Route: ");
    for (int i = 0; i < mx_strlen(str_path); i++) {
        mx_printstr(islands[mx_ctoi(str_path[i])]);
        if (str_path[i + 1]) {
            mx_printstr(" -> ");
        }
    }
    mx_printstr("\n");
}

static void mx_print_current_path(char *str_path, char **islands) {
    int length = mx_strlen(str_path);
    int first_island = 0;
    int second_island = length - 1;

    mx_printstr("Path: ");
    mx_printstr(islands[mx_ctoi(str_path[first_island])]);
    mx_printstr(" -> ");
    mx_printstr(islands[mx_ctoi(str_path[second_island])]);
    mx_printstr("\n");
}

static void mx_print_boundary() {
    for (int i = 0; i < 40; i++) {
        mx_printstr("=");
    }
    mx_printstr("\n");
}
