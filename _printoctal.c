#include "main.h"

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
