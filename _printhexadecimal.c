#include "main.h"

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
