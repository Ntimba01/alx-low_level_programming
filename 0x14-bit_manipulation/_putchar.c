#include "main.h"
#include <unistd.h>
/**
 * _putchar - writing a single character to the standard output.
 * @c: write character to file descriptor 1,  corresponds to the stdout
 *
 * Return: 1 if successful
 *         -1 for failure
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
