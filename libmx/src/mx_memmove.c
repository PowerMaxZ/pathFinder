#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len)
{
	char *cpy;
	if (src == NULL || dst == NULL)
		return NULL;
	if (!(cpy = (char*)malloc(sizeof(char*) * len)))
		return NULL;
	cpy = mx_strncpy(cpy, src, len);
	dst = (void*)mx_strncpy(dst, cpy, len);
	free(cpy);
	return dst;
}
