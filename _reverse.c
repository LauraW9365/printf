#include "main.h"

/**
 * prints_reverse - a function that prints a sting in reverse
 * @x:list of arguments
 * Return:length of the string
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
