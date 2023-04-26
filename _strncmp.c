#include "main.h"

/**
 * _strncmp - compares two strings for the first n bytes
 * @s1: first string to compare
 * @s2: the other  string to be compared with
 * @n: the number of bytes to compare
 * Return: the difference of the two strings
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-10);
}
