#include "main.h"

/**
 * print_rot13 - a function that prints the rot13 string
 * @q: list of arguments
 * Return: length of the string
*/

int print_rot13(va_list q)
{
	int m;
	int n;
	char *s = va_arg(q, char *);

	char r13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char V[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (s == NULL)
		return (-1);

	for (n = 0; s[n]; n++)
	{
		if (s[n] < 'A' || (s[n] > 'Z' && s[n] < 'a') || s[n] > 'z')
			_putchar(s[n]);
		else
		{
			for (m = 0; m <= 52; m++)
			{
				if (s[n] == r13[m])
					_putchar(V[n]);
			}
		}
	}
	return (n);
}

#include "main.h"

/**
 * prints_reverse - a function that prints a string in reverse
 * @x: list of arguments
 * Return: length of the string
*/

int prints_reverse(va_list x, char *p)
{
	int m = 0, n;

	char *s = va_arg(x, char *);
	(void)p;

	if (!s)
		s  = "(null)";
	
	while (s[m])
		m++;

	for (n = m - 1; n >= 0; n--)
		_putchar(s[n]);

	return (m);
}





