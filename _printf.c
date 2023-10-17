#include "main.h"

/**
 * _printf - function that produces output according to this format specifiers
 * %c, %s ,%%, %i and %d.
 * @format: a list of types passed to string format:
 * c: character
 * s: string
 * %: print modulo
 * %i, %d: integer
 * Return: Number of printed bytes exluding '\0', otherwise return 0.
*/
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0;
	int (*func)(va_list);
	int len = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[count])
	{
		if (format[count] != '%')
			write(1, &format[count], 1);
		else if (format[count] == '%')
		{
			count++;
			len -= 2;
			func = get_ft_spec(format[count]);
			len += (*func)(args);
		}
		count++;
	}
	va_end(args);
	return (count + len);
}
