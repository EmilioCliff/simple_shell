#include "main.h"

/**
 * _strcmp - Compares two strings
 * @argv_given: first string to compare
 * @command: second string which is the command
 * Return: if the strings are equal return 1
 * otherwise return-1
 */

int _strcmp(char *argv_given, char *command)
{
	int i = 0;

	while (arg_given[i] != "\0" && command[i] != "\0")
	{
		if (argv_given[i] != command[i])
			return (-1);
		i++;
	}
	return (1);
}
