#include "main.h"
/**
 * _strcmp - compares two stings
 * @argv_given:  first string to compare
 * @command: second string which is the command
 * Return: if the strings are equal it return 1
 *			if the strings are not equal it return -1
 */
int _strcmp(char *argv_given, char *command)
{
	int i = 0;

	while (argv_given[i] != '\0' && command[i] != '\0')
	{
		if (argv_given[i] != command[i])
			return (-1);
		i++;
	}
	return (1);
}

