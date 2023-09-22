#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints standard output
 * @filename: name of the file text is being  read
 * @letters: number of letters it should read and print file
 *
 * Return: actual number of letters it could read and print always
 * 0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t redt, redw;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	redt = read(fd, buf, letters);
	redw = write(STDOUT_FILENO, buf, redt);

	free(buf);
	close(fd);
	return (redw);
}
