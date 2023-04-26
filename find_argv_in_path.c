#include "main.h"
/**
 * find_argv_in_path - Finds if the user command is in the PATH variable
 * @path: the list of directories it checkes
 * @argv: the command input by the user
 * Return: on success it return the full path to the command
 *			if it fails it returns a NULL string
 */
char *find_argv_in_path(char *path, char *argv)
{
	char *dir, *command_path, *path_copy;
	int len_argv = 0;

	len_argv = _strlen(argv);
	path_copy = malloc(sizeof(char) * _strlen(path));
	if (path_copy == NULL)
	{
		perror("malloc");
		exit (-1);
	}
	_strcpy(path_copy, path);
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		command_path = malloc(_strlen(dir) + len_argv + 2);
		if (command_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcat(command_path, dir);
    	_strcat(command_path, "/");
    	_strcat(command_path, argv);
		if (access(command_path, F_OK) == 0)
		{
			return (command_path);
		}
		dir = strtok(NULL, ":");
	}
	command_path = NULL;
	free(command_path);
	free(path_copy);
	return (command_path);
}

