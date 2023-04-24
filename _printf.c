#include "main.h"

/**
 * _printf - produces output accoridng to a format
 * @format: the format of the output
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int m = 0, l = 0;
	char c, *s;

	va_list args;
	va_start(args, format);
	
	if (format == NULL)
		return (-1);

	for (; format[m] != '\0'; m++)
	{
		if (format[m] != '%')
		{
			_putchar(format[m]);
			l++;
		}
		else if (format[m + 1] != 's' && format[m + 1] != 'c')
		{	
			_putchar('%');
			l++;
			if (format[m +1] == '%')
                                m++;
                }
		else if (format[m + 1] == 'c')
		{
			c  = va_arg(args, int);
			_putchar(c);
			l++;
			m++;
		}
		else if (format[m + 1] == 's')
		{
			s = va_arg(args, char*);
			while(*s)
			{
				_putchar(*s++);
				l++;
				m++;
			}
		}
		m++;
	}
	va_end(args);
	return (l);
}
