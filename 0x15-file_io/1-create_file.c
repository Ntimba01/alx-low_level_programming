#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * Calculate the length of the text_content if it's not NULL
 * Open the file for writing (O_CREAT creates the file if it doesn't exist)
 * @text_content: A pointer to a string to Write text_content to the file
 * @filename: A0 pointer to the name of the file to create.
 * Return: If the function fails return (-1).
 * Close the file descriptor and return success (1)
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int redw,len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	redw = write(fd, text_content, len);

	if (fd == -1 || redw == -1)
		return (-1);

	close(fd);

	return (1);
}


