/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:43:18 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/17 21:36:09 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_tile(t_game *g, int y, int x)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img_floor, x * TILE_SIZE, y
		* TILE_SIZE);
	if (g->map[y][x] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img_wall, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (g->map[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_collect, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (g->map[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_exit, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (g->map[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_player, x * TILE_SIZE, y
			* TILE_SIZE);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	mlx_clear_window(g->mlx, g->win);
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			render_tile(g, y, x);
			x++;
		}
		y++;
	}
}
