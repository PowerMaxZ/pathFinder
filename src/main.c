#include "pathFinder.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        mx_printstr("usage: ./pathfinder [filename]");
        return 0;
    }
    char* fil = mx_file_to_str(argv[1]);
    if (fil == NULL) {
        int f = open(argv[1], O_RDONLY);
        if (f < 1) {
            mx_printstr("error: file ");
            mx_printstr(argv[1]);
            mx_printstr(" doesn't exist");
            return 0;
        }
        else {
            mx_printstr("error: file ");
            mx_printstr(argv[1]);
            mx_printstr(" is empty");
            return 0;
        }
    }
    char **islands = file_error_check(fil);
    if (islands == NULL)
        return 0;
    if (error_number(islands))
        return 0;
}
