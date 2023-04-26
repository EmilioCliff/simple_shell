#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
	pid_t pid;
	char *lineptr = NULL, *lineptr_cpy = NULL, *denim, *token = NULL, *path = NULL, *path_name = NULL;
	size_t n = 0;
	ssize_t no_of_char = 0;
	int i = 0,/* count = 0,*/ status, /*result,*/ cmp_rslt;
	char **argv;
	int argc = 0;

	denim = " \n";

	while(1)
	{
	print_dir();
	no_of_char = getline(&lineptr, &n, stdin);
	if (no_of_char == -1)
	{
		_printf("Exiting Terminal\n");
		return (-1);
	}
	lineptr_cpy = malloc(sizeof(char) * no_of_char);
	if (lineptr_cpy == NULL)
	{
		perror("malloc");
		return (-1);
	}
	_strcpy(lineptr_cpy, lineptr);

	token = strtok(lineptr_cpy, denim);

	while (token != NULL)
	{
		argc++;
		token = strtok(NULL, denim);
	}
	argc++;
	free(lineptr_cpy);
	argv = malloc(sizeof(char *) * argc);
	if (argv == NULL)
	{
		perror("malloc");
		return (-1);
	}
	token = strtok(lineptr, denim);
	cmp_rslt = _strcmp(token, "cd");
	if (cmp_rslt == 1)
	{
		token = strtok(NULL, denim);
		chdir(token);
		continue;
	}
	cmp_rslt = _strcmp(token, "exit");
	if (cmp_rslt == 1)
	{
		_printf("Exiting Terminal\n");
		exit(-1);
	}
	argv[0] = token;
	for (i = 1; argv[i - 1] != NULL; i++)
	{
		argv[i] = strtok(NULL, denim);
	}
	argv[i] = NULL;
	path = _getenv("PATH");
	path_name = find_argv_in_path(path, argv[0]);
	if (path_name == NULL)
	{
		_printf("command not found: %s\n", argv[0]);
		continue;
	}
	
	pid = fork();
	if (pid == 0)
	{
	execve(path_name, argv,  NULL);
	perror("execve");
	}
	else if (pid == -1)
	{
		_printf("forking failed");
	}
	else 
	{
		wait(&status);
	}
	}	
	/*free(lineptr_cpy);*/
	/*free_all(lineptr_cpy);*/
	for (i = 0; argv[i] != NULL; i++)
		free_all(argv[i]);
	free_all(argv);
	free_all(path);
	free_all(path_name);		
	return (0);
}


