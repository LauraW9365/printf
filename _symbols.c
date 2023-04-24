#include "main.h"

/**
 * prints_character - prints character
 * @args: the list of arguments
 * Return: characters printed
*/

int prints_character(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);

}

/**
 * prints_string - prints a string
 * @args: list of arguments
 * Return: characters printed
*/

int prints_string(va_list args)
{
	int m = 0;

	char *strg;

	strg = va_arg(args, char*);

	if (strg == NULL)
		strg = "(null)";

	for (; strg[m] != 0; m++)

		_putchar(strg[m]);

	return (m);

}

/**
 * prints_percent - prints the percent smybol
 * @args: the list of arguments
 * Return: characters printed
*/

int prints_percent(va_list args)
{
	_putchar('%');
		return (1);
}
