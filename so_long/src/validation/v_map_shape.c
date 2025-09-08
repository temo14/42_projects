/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:47:44 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/13 19:48:17 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(char **map, int width)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (j >= width)
				return (0);
			j++;
		}
		if (j != width)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == height - 1 || j == 0 || j == width - 1)
				&& map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_walls_and_shape(char **map)
{
	int	width;
	int	height;

	if (!map || !map[0])
		return (0);
	width = map_width(map);
	height = map_height(map);
	if (width < 3 || height < 3)
		return (0);
	if (!check_rectangle(map, width))
		return (0);
	if (!check_walls(map, width, height))
		return (0);
	return (1);
}
