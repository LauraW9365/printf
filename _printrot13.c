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
	char *strng = va_arg(q, char *);

	char r13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char V[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (strng == NULL)
		return (-1);

	for (n = 0; strng[n]; n++)
	{
		if (s[n] < 'A' || (s[n] > 'Z' && s[n] < 'a') || s[n] > 'z')
			_putchar(s[n]);
		else
		{
			for (m = 0; m <= 52; m++)
			{
				if (strng[n] == r13[m])
					_putchar(V[n]);
			}
		}
	}
	return (n);
}
