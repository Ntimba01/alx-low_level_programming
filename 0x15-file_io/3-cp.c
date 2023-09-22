#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buf - It allocates memory for a buffer of 1024 bytes using malloc.
 * if memory allocation is successful by testing if the buffer pointer is NULL.
 * @file: The error message includes the file name provided as file.
 *
 * Return: A pointer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: unable to write %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - attempts to close the file descriptor use close function
 * @fd: integer argument fd representing the file descriptor to be closed.
 */
void close_file(int fd)
{
	int redc;

	redc = close(fd);

	if (redc == -1)
	{
		dprintf(STDERR_FILENO, "Error: unable to close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copy a contant of a file to other file.
 * @argc: arguments numbers supplied to the program.
 * @argv: A pointers to the args array
 *
 * Return: 0 always successeful
 *
 * Description: incorrect argument count exit with code 97.
 *              file doesn't exist or can't read exit with code 98.
 *              cannot created or cannot be written  exit with code 99.
 *              file_to or_from cannot be closed exit with code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, redr, redw;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy from_file to_file \n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	redr = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || redr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: uable to read %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		redw = write(to, buffer, redr);
		if (to == -1 || redw == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: unable to write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		redr = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (redr > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

