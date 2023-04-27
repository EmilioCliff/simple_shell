#include "main.h"

void _printf(char *format, ...)
{
	int i;

	va_list args;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
		{
			case 'd':
			{
				int value = va_arg(args, int);
				char buffer[32];
				int len = 0;
				if (value < 0)
				{
					buffer[len++] = '-';
					value = -value;
				}
				do {
					buffer[len++] = value % 10 + '0';
					value /= 10;
				} while (value > 0);
				for (i = 0; i < len / 2; i++)
				{
					char temp = buffer[i];
					buffer[i] = buffer[len - i - 1];
					buffer[len - i - 1] = temp;
				}
				write(STDOUT_FILENO, buffer, len);
				break;
			}
			case 's':
		{
			char *value = va_arg(args, char*);
			int len = _strlen(value);
			write(STDOUT_FILENO, value, len);
			break;
		}
			default:
		{
			char unknown[] = "Unknown format specifier: ";
			write(STDOUT_FILENO, unknown, _strlen(unknown));
			write(STDOUT_FILENO, format, 1);
			break;
		}
		}
		}
		else
		{
			char c = *format;
			write(STDOUT_FILENO, &c, 1);
		}
		format++;
	}
	va_end(args);
}
