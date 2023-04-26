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

/**
 * put_s - prints character
 * @s: string to be printed
 * Return: number
*/

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
