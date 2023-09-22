#include "main.h"

/**
 * binary_to_uint - converts a binary representation to an unsigned integer.
 * unsigned integer variable dec_val to store the decimal of the binary string.
 *
 *  If NULL, function returns 0, indicating an error or an invalid input
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[i] - '0');
	}

	return (dec_val);
}

