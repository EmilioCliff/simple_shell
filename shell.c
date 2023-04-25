#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
void print_dir()
{
	char ch[1024];
	getcwd(ch, sizeof(ch));
	printf("%s$", ch);
}
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
int _strcmp(char *argv_given,char *command )
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
int main()
{
	
	char *lineptr = NULL, *lineptr_cpy, *denim, *token;
	size_t n = 0;
	ssize_t no_of_char;
	int token_num = 0, i = 0, count = 0, status, result, cmp_rslt;
	/*char *envp[] = {PATH, NULL};*/
	char **argv;

	denim = " \n";
	while(1)
	{
	print_dir();
	no_of_char = getline(&lineptr, &n, stdin);
	if (no_of_char == -1)
	{
		printf("Exiting Terminal\n");
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
		token_num++;
		token = strtok(NULL, denim);
	}
	token_num++;

	argv = malloc(sizeof(char *) * token_num);
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
		perror("access");
		continue;
	}
	pid_t pid = fork();
	if (pid == 0)
	{
	execve(argv[0], argv,  NULL);
	perror("execve");
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


