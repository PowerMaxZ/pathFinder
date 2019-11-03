#include "libmx.h"

void *mx_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int i;
	char *dest;
	const char *sourc;

	if (src == NULL || dst == NULL)
		return NULL;
	dest = dst;
	sourc = src;
	i = 0;
	while (i < n)
	{
		dest[i] = sourc[i];
		i++;
	}
	return dst;
}
