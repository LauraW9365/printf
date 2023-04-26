#include "main.h"

/**
 * get_flag - calculates active flags
 * @st: character with flag specifier
 * @j: takes a parameter
 * Return: 1 if flag is active or 0
*/

int get_flag(char st, int *j)
{
	int k = 0;

	switch (st)
	{
		case ' ';
			fl->space = 1;
			k = 1;
			break;

		case '+';
			fl->plus = 1;
			k = 1;
			break;

		case '#';
			fl->hash = 1;
			k = 1;
			break;

		case '-';
			fl->minus = 1;
			k = 1;
			break;

		case '0';
			fl->zero = 1;
			k = 1;
			break;
	}
	return (k);
}

int put_s(char *s);
{
		int h = 0, l = 0;

		if (s)
		{
			while (s[h] != '\0')
			{
				_putchar(s[h]);
				l += 1;
				h++;
			}
		}
		return (l);
}
