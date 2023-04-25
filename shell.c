#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
	char *prompt = "USER$";
	char *lineptr = NULL, *lineptr_cpy, *denim, *token;
	size_t n = 0;
	ssize_t no_of_char;
	int token_num = 0, i = 0, count = 0, status, result;
	char *envp[] = {PATH, NULL};
	char **argv;
	printf("%s\n", envp[0]);

	denim = " \n";
	while(1)
	{
	printf("%s", prompt);
	no_of_char = getline(&lineptr, &n, stdin);
	if (no_of_char == -1)
	{
		printf("Exiting Terminal\n");
		return (-1);
	}
	lineptr_cpy = malloc(sizeof(char) * no_of_char);
	if (lineptr_cpy == NULL)
	{
		printf("failed to allocate memory");
		return (-1);
	}
	strcpy(lineptr_cpy, lineptr);

	token = strtok(lineptr_cpy, denim);

	while (token != NULL)
	{
		token_num++;
		token = strtok(NULL, denim);
	}
	token_num++;

	argv = malloc(sizeof(char *) * token_num);
	if (argv == NULL)
	{
		printf("failed to allocate memory");
		return (-1);
	}
	token = strtok(lineptr, denim);
	if (strcmp(token, "cd") == 0)
	{
		token = strtok(NULL, denim);
		chdir(token);
		continue;
	}
	if (strcmp(token, "exit") == 0)
	{
		printf("Exiting Terminal\n");
		exit(-1);
	}
	argv[0] = token;
	for (i = 1; argv[i - 1] != NULL; i++)
	{
		argv[i] = strtok(NULL, denim);
	}
	argv[i] = NULL;
	result = access(argv[0], F_OK);
	if (result == -1)
	{
		printf("Path not found\n");
		continue;
	}
	pid_t pid = fork();
	if (pid == 0)
	{
	execve(argv[0], argv,  envp);
	printf("execve failed\n");
	}
	else if (pid == -1)
	{
		printf("forking failed");
	}
	else 
	{
		wait(&status);
	}
	if (argv != NULL)
		free(argv);
	if (lineptr_cpy != NULL)
		free(lineptr_cpy);
	}
	return (0);
}

