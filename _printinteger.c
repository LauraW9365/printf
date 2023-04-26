#include "main.h"

/************** _print_unsigned_integer.c **************/
/**
 * print_unsigned - Prints an unsigned number
 * @ar: Arguments list
 * @buf: Buffer array to handle print
 * @fg: Calculates active flags
 * @w: width
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_unsigned(va_list ar, char buf[],
	int fg, int w, int pr, int sz)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(ar, unsigned long int);

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

/************** _printinteger.c **************/
/**
 * print_int - Prints integer
 * @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg: Calculates active flags
 * @w: width
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list arg, char buf[],
	int fg, int w, int pr, int sz)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(arg, long int);
	unsigned long int num;

	n = convert_size_number(n, sz);

	if (n == 0)
		buf[i--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
		while (num > 0)
		{
			buf[i--] = (num % 10) + '0';
			num /= 10;
		}
		i++;
	return (write_number(is_negative, i, buf, fg, w, pr, sz));
}

