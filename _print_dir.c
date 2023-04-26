#include "main.h"
/**
 * print_dir - prints the directory of the current working dir
 */
void print_dir(void)
{
	char ch[1024];

	getcwd(ch, sizeof(ch));
	printf("%s$", ch);
}
