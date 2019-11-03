#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow == 0)
        return 1;
    if (pow == 1)
        return n;
    if (pow < 0)
        return 1;
    double res = n;
    for (; pow > 1; pow--) {
        res = res * n;
    }
    return res;
}
