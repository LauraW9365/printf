#include "main.h"

/**
 * _printf - produces output accoridng to a format
 * @format: the format of the output
 *
 * Return: the number of characters printed,
 * excluding the null byte used to end output to strings
*/

int _printf(const char *format, ...);
{
	unsigned int m = 0, _value = 0;

	va_list X;

	va_start(X, format);

	if (format == NULL)
		return (-1);

	for (m = 0; format[m] != '\0'; m++)
	{
		if (format[m] != '%')

			_putchar(format[m]);
		}
		else if (format[m + 1] == 's')
		{

			int _val = put_s(va_arg(X, char *));

			m++;

			_value += (_val - 1);

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
		_value += 1;
	}
	return (_value);
}
