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

bool isletter(char c);
char** file_error_check(char *str);
int mx_strlen(const char *s);
int error_number(char **file_d);

#endif
