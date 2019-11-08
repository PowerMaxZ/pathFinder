#include "pathFinder.h"

void mx_printerror(const char *error) {
    write(2, error, mx_strlen(error));
}
