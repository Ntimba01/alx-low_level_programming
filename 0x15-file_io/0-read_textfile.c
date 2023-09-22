#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * read_textfile - files print to STDOUT read and write
 * @filename:read text file using the file name
 * @letters: number of letters is to be read
 * Return: Clean up and return the number of bytes read and written
 * when function fails or filename is NULL it must be 0
 * return to 0 always
 */

ssize_t read_textfile(const char, filename, size_t letters)
{
	ssize_t fd;
	char *buf;
	ssize_t t, w;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}
	w = write(STDOUT_FILENO, buf, t);
	if (w == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}
	t = read(buf, fd, letters);
	if (t == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}
	close(fd);
	free(buf);
	return (w);
}
