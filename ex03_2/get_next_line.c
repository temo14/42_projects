#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char		*temp;
	int			bytes;
	int			line_len;
	static char	*saved = NULL;
	char		buf[BUFFER_SIZE + 1];
	int			saved_len;

	while (1)
	{
		if (saved)
		{
			i = 0;
			while (saved[i] && saved[i] != '\n')
				i++;
			if (saved[i] == '\n')
			{
				line = malloc(i + 2);
				for (int j = 0; j <= i; j++)
					line[j] = saved[j];
				line[i + 1] = '\0';
				if (saved[i + 1])
				{
					line_len = 0;
					while (saved[i + 1 + line_len])
						line_len++;
					temp = malloc(line_len + 1);
					for (int j = 0; j < line_len; j++)
						temp[j] = saved[i + 1 + j];
					temp[line_len] = '\0';
					free(saved);
					saved = temp;
				}
				else
				{
					free(saved);
					saved = NULL;
				}
				return (line);
			}
		}
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			if (saved && saved[0])
			{
				line = saved;
				saved = NULL;
				return (line);
			}
			free(saved);
			saved = NULL;
			return (NULL);
		}
		buf[bytes] = '\0';
		if (saved)
		{
			saved_len = 0;
			while (saved[saved_len])
				saved_len++;
			temp = malloc(saved_len + bytes + 1);
			for (int i = 0; i < saved_len; i++)
				temp[i] = saved[i];
			for (int j = 0; j < bytes; j++)
				temp[i + j] = buf[j];
			temp[saved_len + bytes] = '\0';
			free(saved);
			saved = temp;
		}
		else
		{
			saved = malloc(bytes + 1);
			for (int i = 0; i < bytes; i++)
				saved[i] = buf[i];
			saved[bytes] = '\0';
		}
	}
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
