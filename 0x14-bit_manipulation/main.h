#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
void print_binary(unsigned long int n);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int binary_to_uint(const char *b);
int _atoi(const char *s);
int get_bit(unsigned long int n, unsigned int index);
int get_endianness(void);
unsigned int flip_bits(unsigned long int s, unsigned long int t);

#endif /*main.h*/

