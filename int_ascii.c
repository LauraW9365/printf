#include "main.h"

/**
 * intascii - integer to ascii
 * @n: Unsigned long integer
 * @b: Base Number
 * @pt: pointer
 * Return: char
 **/
char *intascii(long int n, int b)
{
        static char *array = "0123456789abcdef";
        static char buffer[50];
        char sign = 0;
        char *pt;
        unsigned long n = num;

        if (num < 0)
        {
                n = -num;
                sign = '-';
        }
        pt = &buffer[49];
        *pt = '\0';

        do      {
                *--pt = array[n % b];
                n /= base;
        } while (n != 0);

        if (sign)
                *--pt = sign;
        return (pt);
}
