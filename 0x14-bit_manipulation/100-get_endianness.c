#include "main.h"

/**
 * get_endianness - check the endianness of the system
 * Return: 0 for big_endian, 1 for little_endian
 */

int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}

