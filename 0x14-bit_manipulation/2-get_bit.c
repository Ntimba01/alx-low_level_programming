#include "main.h"

/*
 * get_bit - retrieve bit at a given index from unsigned long integer(n)
 * @index: greater than 63 (which is the maximum index for a 64-bit integer)
 *
 * Return: bit_val, which is either 0 or 1, or -1 in case of an invalid index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (n >> index) & 1;

	return (bit_val);
}
