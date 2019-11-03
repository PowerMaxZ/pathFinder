#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int k = 0;
    unsigned long tmp = nbr;
    while (tmp != 0) {
        tmp /= 16;
        k++;
    }
    char *hexaDeciNum = (char *)malloc(k + 1); 
    k--;
    while(nbr != 0) {    
        unsigned long temp = 0; 
        temp = nbr % 16; 
        if (temp < 10) { 
            hexaDeciNum[k] = temp + 48; 
            k--; 
        } 
        else { 
            hexaDeciNum[k] = temp + 87; 
            k--; 
        }
        nbr = nbr / 16;
    }
    return hexaDeciNum;
}
