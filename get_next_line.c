#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	int			newline_pos;
	int			bytes_read;
	int			saved_length;
	char		*current_line;
	char		*temp_buffer;
	char		read_buffer[BUFFER_SIZE + 1];
	static char	*saved_data = NULL;
	int			i;

	newline_pos = 0;
	current_line = NULL;
	bytes_read = 0;
	saved_length = 0;
	while (1)
	{
		// First check if we have data saved from previous reads
		if (saved_data)
		{
			// Look for newline in saved data
			newline_pos = 0;
			while (saved_data[newline_pos] && saved_data[newline_pos] != '\n')
				newline_pos++;
			// If we found a newline, extract the line
			if (saved_data[newline_pos] == '\n')
			{
				// Allocate memory for line including newline
				current_line = (char *)malloc(newline_pos + 2);
				for (i = 0; i <= newline_pos; i++)
					current_line[i] = saved_data[i];
				current_line[newline_pos + 1] = '\0';
					// FIXED: Proper null termination
				// Save remaining data after newline (if any)
				if (saved_data[newline_pos + 1])
				{
					// Calculate length of remaining data
					i = 0;
					while (saved_data[newline_pos + 1 + i])
						i++;
					// Allocate and copy remaining data
					temp_buffer = (char *)malloc(i + 1);
					for (int j = 0; j < i; j++)
						// FIXED: Changed <= to < to avoid buffer overflow
						temp_buffer[j] = saved_data[newline_pos + 1 + j];
					temp_buffer[i] = '\0';
					free(saved_data);
					saved_data = temp_buffer;
				}
				else
				{
					// No remaining data, clear saved_data
					free(saved_data);
					saved_data = NULL;
				}
				return (current_line);
			}
		}
		// Read more data from file
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		// Handle end of file or read error
		if (bytes_read <= 0)
		{
			if (saved_data)
			{
				// Return whatever is left in saved_data as final line
				current_line = saved_data;
				saved_data = NULL;
				return (current_line);
			}
			// FIXED: Only free if saved_data is not NULL
			if (saved_data)
				free(saved_data);
			saved_data = NULL;
			return (NULL);
		}
		// Null terminate the read buffer
		read_buffer[bytes_read] = '\0';
		// Append new data to saved_data
		if (saved_data)
		{
			// Calculate current saved_data length
			saved_length = 0;
			while (saved_data[saved_length])
				saved_length++;
			// Allocate memory for combined data
			temp_buffer = malloc(saved_length + bytes_read + 1);
			// Copy existing saved data
			for (i = 0; i < saved_length; i++)
				temp_buffer[i] = saved_data[i];
			// Append new data
			for (int j = 0; j < bytes_read; j++)
				temp_buffer[saved_length + j] = read_buffer[j];
			temp_buffer[saved_length + bytes_read] = '\0';
			free(saved_data);
			saved_data = temp_buffer;
		}
		else
		{
			// First time reading, allocate and copy
			saved_data = (char *)malloc(bytes_read + 1);
			for (i = 0; i < bytes_read; i++)
				saved_data[i] = read_buffer[i];
			saved_data[bytes_read] = '\0';
		}
		// IMPROVED: Reset newline_pos for next iteration of saved_data check
		newline_pos = 0;
	}
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file\n");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}