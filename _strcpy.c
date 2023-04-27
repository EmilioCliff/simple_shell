#include "main.h"
/**
 * _strcpy - copy a string from source to a destination string
 * @dest: string to be copied to
 * @src: string to copy from
 */
void _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
