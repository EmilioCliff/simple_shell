#include "main.h"
/**
 * free_all - frees all memory allocated dynamically
 * @ptr: the variable to free
 */
void free_all(void *ptr)
{
	if (ptr == NULL)
		return;
	free(ptr);
}
