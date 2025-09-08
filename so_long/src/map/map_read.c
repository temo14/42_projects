/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:40:05 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/18 20:03:40 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*process_line(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n' && line[len] != '\r')
		len++;
	line[len] = '\0';
	if (len == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	**allocate_map(void)
{
	char	**map;

	map = calloc(MAX_HEIGHT + 1, sizeof(char *));
	return (map);
}

char	**read_map_lines(int fd, char **map, int i)
{
	char	*line;
	char	*processed_line;

	line = get_next_line(fd);
	while (line)
	{
		if (i >= MAX_HEIGHT)
		{
			free(line);
			free_map(map);
			close(fd);
			ft_printf("Error\nMap too large, max height:%d\n", MAX_HEIGHT);
			return (NULL);
		}
		processed_line = process_line(line);
		if (processed_line)
			map[i++] = processed_line;
		else
			free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (validate_map_result(map, i));
}

char	**validate_map_result(char **map, int line_count)
{
	if (line_count == 0)
	{
		free_map(map);
		ft_printf("Error\nEmpty map file\n");
		return (NULL);
	}
	return (map);
}

char	**read_map(char *map_address)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(map_address, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCannot open map file: %s\n", map_address);
		return (NULL);
	}
	map = allocate_map();
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	return (read_map_lines(fd, map, i));
}
