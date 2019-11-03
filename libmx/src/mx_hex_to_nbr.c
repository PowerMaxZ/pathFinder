#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    long base = 1; 
    int len = 0;
    int i = 0;
    while (hex[i] != '\0') {
        len++;
        i++;
    }
    unsigned long dec_val = 0; 
      
    for (int i= len - 1; i >= 0; i--) 
    {    
        if (hex[i] >= '0' && hex[i] <= '9') 
        { 
            dec_val += (hex[i] - 48) * base; 
            base = base * 16; 
        } 
        else if (hex[i] >= 'A' && hex[i] <= 'F') 
        { 
            dec_val += (hex[i] - 55) * base; 
            base = base * 16; 
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec_val += (hex[i] - 87) * base;
            base = base * 16;
        }
    } 
      
    return dec_val;
}
