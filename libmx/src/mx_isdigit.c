#include "libmx.h"

bool mx_isdigit(int c)
{
	bool i = false;
	if (c >= '0' && c<='9')
		i = true;
	return i; 
}
