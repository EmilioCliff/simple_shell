#include "main.h"

/**
 * bfree - Frees pointer, NULLs address
 * @ptr: pointer address to free
 * Return: 1 if fred, otherwise 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
