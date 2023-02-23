#include "main.h"

/**
 * _isalpha -chacks for alphabetic charater
 * @C: the charater to be checked
 * Return: 1 if c is a latter, 0 otherwise
 */
int _isalpha(int c )
{
	return ((c <= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
