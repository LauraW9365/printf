#include "main.h"

/**
 * print_binary - Prints an unsigned number
* @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w:  width.
 * @pr: Precision specification
 * @sz: Size specifier
 *@c: count
 * Return: Numbers of char printed.
 */
int print_binary(va_list arg, char buf[],
	int fg, int w, int pr, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int c;

	UNUSED(buf);
	UNUSED(fg);
	UNUSED(w);
	UNUSED(pr);
	UNUSED(sz);

	n = va_arg(arg, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, c = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}

