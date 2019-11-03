#include "libmx.h"

int	mx_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*t1;
	unsigned const char	*t2;
	t1 = (unsigned const char *)s1;
	t2 = (unsigned const char *)s2;
	if (t1 == NULL || t2 == NULL)
		return 0;
	while (n)
	{
		if (*t1 != *t2)
			return *t1 - *t2;
		t1++;
		t2++;
		n--;
	}
	return 0;
}
