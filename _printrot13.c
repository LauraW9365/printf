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

#include "main.h"

/**
 * prints_reverse - a function that prints a string in reverse
 * @x: list of arguments
 * Return: length of the string
*/

int prints_reverse(va_list x)
{
	int j;
	char *strg;
	char *p;

	strg = va_arg(x, char *);

	if (!strg)
		return (-1);

	p = rev_string(strg);

	if (!p)
		p = "(null)";

	for (; p[j] != '\0'; j++)
		_putchar(p[j]);

	return (j);
}





