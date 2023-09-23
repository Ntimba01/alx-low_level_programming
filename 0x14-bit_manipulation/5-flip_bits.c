#include "main.h"

/*
 * flip_bits - count number of bits that are flipped in order to convert
 * @s: first number
 * @t: second number
 *
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int s, unsigned long int t)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = s ^ t;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}

