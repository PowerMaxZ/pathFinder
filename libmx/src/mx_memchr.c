#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char *string;

	if (s == NULL)
		return NULL;
	i = 0;
	string = (void *)s;
	while (i < n)
	{
		if (string[i] == (char)c)
			return &string[i];
		i++;
	}
	return NULL;
}
