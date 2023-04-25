

#include "main.h"

/*************************Handle *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags.
 * @w: get width.
 * @pr: precision specifier
 * @sz: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buf[],
	int flags, int w, int pr, int sz)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(pr);
	UNUSED(sz);

	if (fg & F_ZERO)
		padd = '0';

	buf[i++] = c;
	buf[i] = '\0';

	if (w > 1)
	{
		buf[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buf[BUFF_SIZE - i - 2] = padd;

		if (fg & F_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], w - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buf: Buffer array to handle print
 * @fg:  Calculates active flags
 * @w: get width.
 * @pr: precision specifier
 * @sz: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char bufr[],
	int fg, int w, int pr, int sz)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(sz);

	if ((fg & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (fg & F_PLUS)
		extra_ch = '+';
	else if (fg & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buf, fg, w, pr,
		length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buf: Buffer
 * @fg: Flags
 * @w: width
 * @pr: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buf[i] = padd;
		buf[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buf[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buf[--padd_start] = extra_c;
			return (write(1, &buf[padd_start], i - padd_start) +
				write(1, &buf[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buf[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @fg: Flags specifiers
 * @w: Width specifier
 * @pr: Precision specifier
 * @sz: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buf[],
	int fg, int w, int pr, int sz)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(sz);

	if (pr == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buf[], int ind, int length,
	int w, int fg, char padd, char extra_c, int padd_start)
{
	int i;

	if (wh > length)
	{
		for (i = 3; i < w - length + 3; i++)
			buffer[i] = padd;
		buf[i] = '\0';
		if (fg & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buf[ind], length) + write(1, &buf[3], i - 3));
		}
		else if (!(fg & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[3], i - 3) + write(1, &buf[ind], length));
		}
		else if (!(fg & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[padd_start], i - padd_start) +
				write(1, &buf[ind], length - (1 - padd_start) - 2));
		}
	}
	buf[--ind] = 'x';
	buf[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buf[ind], BUFF_SIZE - ind - 1));
}

