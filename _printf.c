#include "main.h"

/**
 * _printf - produces output accoridng to a format
 * @format: the format of the output
 * Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	unsigned int m = 0, x_value = 0;

	va_list arg;

	va_start(arg, format);

	if (format == NULL)
		return (-1);

	for (m = 0; format[m] != '\0'; m++)
	{
		if (format[m] != '%')

			_putchar(format[m]);
		}
		else if (format[m + 1] == 's')
		{
			int _val = va_arg(arg, char *);

			m++;

			x_value += (x_val - 1);

		}
		else if (format[m + 1] == 'c')
		{
			_putchar(va_arg(X, int);
			m++;
		}

		else if (format[m + 1] != 's' && format[m + 1] != 'c')
		{

			_putchar('%');
			m++;
		}
		x_value += 1;
	}
	return (x_value);
}
