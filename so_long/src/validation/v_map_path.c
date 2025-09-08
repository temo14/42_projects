/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:48:36 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/13 20:08:23 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <string.h>

static char	**copy_map(char **map)
{
	char	**copy;
	int		i;
	int		h;

	h = map_height(map);
	copy = malloc(sizeof(char *) * (h + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < h)
	{
		copy[i] = strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, int found[2])
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		found[0]++;
	if (map[y][x] == 'E')
	{
		found[1] = 1;
		return ;
	}
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, found);
	flood_fill(map, x - 1, y, found);
	flood_fill(map, x, y + 1, found);
	flood_fill(map, x, y - 1, found);
}

static void	find_start_and_total(char **map, int *px, int *py, int *total_c)
{
	int	i;
	int	j;

	*total_c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*px = j;
				*py = i;
			}
			if (map[i][j] == 'C')
				(*total_c)++;
			j++;
		}
		i++;
	}
}

int	validate_path(char **map)
{
	char	**copy;
	int		px;
	int		py;
	int		total_c;
	int		found[2];

	px = 0;
	py = 0;
	find_start_and_total(map, &px, &py, &total_c);
	copy = copy_map(map);
	if (!copy)
		return (0);
	found[0] = 0;
	found[1] = 0;
	flood_fill(copy, px, py, found);
	free_map(copy);
	return (found[0] == total_c && found[1] == 1);
}
