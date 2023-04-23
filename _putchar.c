#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character z for stdout
 * @z: The character to print
 *
 * Return: 1 on success
*/

int _putchar(char z)
{
	
	return (write(1, &z, 1));

}
