#include "libmx.h"

char *mx_itoa(int number) {
    int flag = 1;
    int size = 0;
    if (number < 0) {
        flag = -1;
        number = -number;
        size++;
    }
    int temp = number;
    while (temp != 0) {
        size++;
        temp /= 10;
    }
    char *result = (char *)malloc(size + 1);
    int end = size;
    size--;
    if (number == -2147483648) {
        result[0] = '-';
        result[1] = '2';
        number += 2000000000;
        number *= -1;
        flag = 1;
    }
    while (number != 0) {
        int temp = number % 10;
        result[size] = temp + 48;
        size--;
        number /= 10;
    }
    if (flag == -1) {
        result[size] = '-';
    }
    result[end] = '\0';
    return result;
}
