#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Points to destination string.
 * @src: Points to string source
 * Return: Pointer to destination string
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i] != "\0")
		i++;
	while (src[j] != "\0")
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = "\0";
	return (dest);
}
