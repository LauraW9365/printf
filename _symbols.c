#include "main.h"

/**
 * print_character - prints character
 * @args: the list of arguments
 * Return: characters printed
*/

int print_character(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);

}

/**
 * print_string - prints a string
 * @args: list of arguments
 * Return: characters printed
*/

int print_string(va_list args)
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
 * print_percent - prints the percent smybol
 * @args: the list of arguments
 * Return: characters printed
*/

int print_percent(va_list args)
{
	(void)args;

	_putchar('%');
		return (1);
}
