#include "pathFinder.h"

static bool mx_add_words(char **arr, char *line);
static void mx_add_word(char **arr, char *new_island);

char **mx_check_text_value(char *text) {
    char **lines = mx_strsplit(text, '\n');
    int count_words = mx_atoi(*lines++);
    char **islands = malloc(sizeof(char *) * (count_words + 1));
    int index_words = 0;
    int index = 0;

    islands[count_words] = NULL;
    for (int i = 0; i < count_words; i++) {
        islands[i] = "";
    }
    while (lines[index]) {
        if (!mx_add_words(islands, lines[index])) {
            mx_printerr(INVLD_LINE, mx_itoa(index + 1));
        }
        index++;
    }
    while (islands[index_words] && mx_strlen(islands[index_words])) {
        index_words++;
    }
    if (index_words < mx_arr_size(islands)) {
        mx_printerr(INVLD_NUM_ISLDS, NULL);
    }
    return islands;
}

static bool mx_add_words(char **arr, char *line) {
    int first_index = mx_get_char_index(line, '-');
    int second_index = mx_get_char_index(line, ',');
    char *new_first_island = NULL;
    char *new_second_island = NULL;

    new_first_island = mx_strnew(first_index);
    new_second_island = mx_strnew(second_index - first_index - 1);
    mx_strncpy(new_first_island, line, first_index);
    mx_strncpy(new_second_island, line + first_index + 1, second_index - first_index - 1);
    if (!mx_strcmp(new_first_island, new_second_island)) {
        return false;
    }
    mx_add_word(arr, new_first_island);
    mx_add_word(arr, new_second_island);
    return true;
}

static void mx_add_word(char **arr, char *new_island) {
    int index = 0;

    while (arr[index] && mx_strlen(arr[index])) {
        if (!mx_strcmp(arr[index], new_island)) {
            return;
        }
        index++;
    }
    if (index >= mx_arr_size(arr)) {
        mx_printerr(INVLD_NUM_ISLDS, NULL);
    }
    arr[index] = new_island;
}
