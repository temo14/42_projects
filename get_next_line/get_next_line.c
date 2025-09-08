/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:10:51 by tbaindur          #+#    #+#             */
/*   Updated: 2025/06/19 20:13:20 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char **reminder)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	if (!reminder || !*reminder)
		return (NULL);
	while ((*reminder)[i] && (*reminder)[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = -1;
	while ((*reminder)[++i] && (*reminder)[i] != '\n')
		line[i] = (*reminder)[i];
	if ((*reminder)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	temp = *reminder;
	if ((*reminder)[i] == '\0')
		*reminder = NULL;
	else
		*reminder = ft_strdup(*reminder + i);
	free(temp);
	return (line);
}

static void	handle_read_error(char **buffer, char **reminder)
{
	free(*buffer);
	free(*reminder);
	*reminder = NULL;
}

static int	process_buffer(char **reminder, char *buffer, int bytes_read)
{
	char	*temp;

	buffer[bytes_read] = '\0';
	temp = *reminder;
	*reminder = ft_strjoin(*reminder, buffer);
	free(temp);
	if (!*reminder)
		return (0);
	return (1);
}

static char	*read_and_join(char **reminder, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(*reminder, '\n') == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			handle_read_error(&buffer, reminder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		if (!process_buffer(reminder, buffer, bytes_read))
		{
			handle_read_error(&buffer, reminder);
			return (NULL);
		}
	}
	free(buffer);
	return (*reminder);
}

char	*get_next_line(int fd)
{
	static char	*reminder = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_join(&reminder, fd))
		return (NULL);
	if (!reminder)
		return (NULL);
	return (ft_extract_line(&reminder));
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("file.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
