#include "main.h"
/**
 * _getenv - gets the full directories of the variable PATH
 * @env: the global variable to find it full directories
 * Return: the string to the full path on success
 */
char *_getenv(const char *env)
{
	char *value = NULL, **envv, *env_var;
	int len_env;

	len_env = _strlen(env);
	for (envv = environ; *envv != NULL; envv++)
	{
		env_var = *envv;
		if (_strncmp((char *)env, env_var, len_env) == 0 && env_var[len_env] == '=')
		{
			value = (char *)malloc(_strlen(env_var) - len_env);
			if (value == NULL)
			{
				perror("malloc");
				exit(-1);
			}
			if (value != NULL)
			{
				_strcpy(value, env_var + len_env + 1);
			}
			break;
		}
	}
	return (value);
}

