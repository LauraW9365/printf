#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w:  width.
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list ar, char buf[],
	int fg, int w, int pr, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(arg, unsigned long int);

	num = convert_size_unsgnd(num, sz);

	if (num == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buf, fg, w, pr, sz));
}
