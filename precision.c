#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed
 * @arg: argument list
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list arg)
{
	int curr_i = *i + 1;
	int pr = -1;

	if (format[curr_i] != '.')
		return (pr);

	pr = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			pr *= 10;
			pr += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			pr = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (pr);
}



