#include "main.h"

/**
 * clear_bit- clear bit at index in an unsigned long integer (*n).
 * @n: pointer to the unsigned long integer to be modified,
 * @index:  position of the bit to clear.
 *
 * Return: 1 success, -1 for error
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

