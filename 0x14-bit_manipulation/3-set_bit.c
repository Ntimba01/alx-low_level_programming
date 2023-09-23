#include "main.h"

/**
 * set_bit - set (change to 1) bit at index in an unsigned long integer (*n)
 * @n:  pointer to the unsigned long integer
 * @index: is out of range, the function returns -1 to indicate an error.
 *
 * Return: 1 if successful, -1 to indicate an error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
