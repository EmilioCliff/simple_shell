#include "main.h"

/**
 * _strcpy - Copies string
 * @dest: string to be copied to
 * @src: string to copy from
 */

void_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != "\0")
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = "\0";
}
