#include "main.h"

/**
 * _printf - produces output accoridng to a format
 * @format: the format of the output
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int m = 0;
	int l = 0;

	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (; format[m] != '\0'; m++)
	{
		if (format[m] != '%')
		{
			_putchar(format[m]);
		}
		else if (format[m + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			m++;
		}
		else if (format[m + 1] == 's')
		{
			int v = put_s(va_arg(args, char *));
			m++;
			l += (v - 1);
		}
		else if (format[m + 1] == '%')
		{
			_putchar('%');
			m++;
		}
		l += 1;
	}
	return (l);
}
