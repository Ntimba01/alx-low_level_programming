#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates 1024 bytes in a buffer
 * @file: The name of the file buffer is storing chars for.
 * Error: Memory allocation failed
 * Return: to buffer that is allocated
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: memory allocation failed to write in %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - close fd and handle errors if the close operation fails
 * @fd: file discriptor must be closed
 * printing is "Error: Can't close fd %d,"
 */

void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: failed to close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - the program Copies the contents of one file to the other file.
 * @argc: number of command-line arguments (argc).
 * supplied (program name, source file, and destination file)
 *
 * program name, source file, and destination file, print stderr code 97.
 * file doesn't exist, can't be read print stderr and exits with error code 98.
 * I/O errors prints an error message to stderr and exits with error code 99.
 * The maximum number of bytes read is 1024
 *
 * Return: (0) always success
 */

int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: copy file from to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	r = read(from, buffer, 1024);
	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: the file can not be read %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: the file can not be writen %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

