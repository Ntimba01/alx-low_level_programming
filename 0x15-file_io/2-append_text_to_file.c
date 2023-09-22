#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


/**
 * Calculate the length of the text_content if it's not NULL
 * Open the file for writing (O_WRONLY | O_APPEND appends to the file)
 * @text_content: The string to add to the end of the files.
 * @filename: A pointer to the name of the files.
 * Return: If the function fails or filename is NULL -1.
 * Write the text_content to the file
 * Close the file descriptor and return success return 1
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	if (o == -1)
		return (-1);

	if (text_content != NULL)
	{
	w = write(o, text_content, len);
	if (w == -1)
	{
		close(o);
		return (-1);
	}
	}
	close(o);
	return (1);
}
