#include "main.h"

/************** _printinteger.c **************/
/**
 * print_int - Prints integer
 * @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w:  width.
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list arg, char buf[],
        int fg, int w, int pr, int sz)
{
        int i = BUFF_SIZE - 2;
        int is_negative = 0;
        long int n = va_arg(arg, long int);
        unsigned long int num;

        n = convert_size_number(n, sz);

        if (n == 0)
                buf[i--] = '0';

        buf[BUFF_SIZE - 1] = '\0';
        num = (unsigned long int)n;

        if (n < 0)
        {
                num = (unsigned long int)((-1) * n);
                is_negative = 1;
        }

        while (num > 0)
        {
                buf[i--] = (num % 10) + '0';
                num /= 10;
        }

        i++;

        return (write_number(is_negative, i, buf, fg, w, pr, sz));
}

/************** _printbinaryl.c **************/

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

/************** _printoctal.c **************/

/**
 * prints_octal - Prints an unsigned number in octal 
 * @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w:  width.
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int prints_octal(va_list arg, char buf[],
        int fg, int w, int pr, int sz)

        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(width);

        num = convert_size_unsgnd(num, sz);

        if (num == 0)
                buffer[i--] = '0';

        buf[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buf[i--] = (num % 8) + '0';
                num /= 8;
        }

        if (fg & F_HASH && init_num != 0)
                buf[i--] = '0';

        i++;

        return (write_unsgnd(0, i, buf, flg, w, pr, sz));
}

/************** _print_usigned_hexadecimal.c **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w:  width.
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list arg, char buf[],
        int fg, int w, int pr, int sz)

{
        return (print_hexa(arg, "0123456789abcdef", buf,
                fg, 'x', w, pr, szS));
}

/************* _printhexadecimal_upper.c **************/
/**
 * printhexa_upper - Prints an unsigned number in upper hexadecimal 
 * @arg: Arguments list
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w:  width.
 * @pr: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int printhexa_upper(va_list arg, char buf[],
        int fg, int w, int pr, int sz)

{
        return (print_hexa(arg, "0123456789ABCDEF", buf,
                fg, 'X', w, pr, sz));
}

/************** _printhexadecimal.c**************/
/**
 * printhexadecimal - Prints a hexadecimal number in lower or upper
 * @arg: Lista of arguments
 * @map_to: Array of values to map the number to
 * @bufr: Buffer array to handle print
 * @fg:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: get width
 * @precision: Precision specification
 * @sz: Size specifier
 * Return: Number of chars printed
 */
int printhexa_upper(va_list arg, char map_to[], char buf[],
        int fg, char flag_ch, int w, int pr, int sz)
{
        int i = BUFF_SIZE - 2;
        unsigned long int num = va_arg(ar, unsigned long int);
        unsigned long int init_num = num;

        UNUSED(w);

        num = convert_size_unsgnd(num, sz);

        if (num == 0)
                buf[i--] = '0';

        buf[BUFF_SIZE - 1] = '\0';

        while (num > 0)
        {
                buf[i--] = map_to[num % 16];
                num /= 16;
        }

        if (fg & F_HASH && init_num != 0)
        {
                buf[i--] = flag_ch;
                buf[i--] = '0';
        }

        i++;

        return (write_unsgnd(0, i, buf, fg, w, pr, sz));
}
