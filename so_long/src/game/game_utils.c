/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:43:04 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/17 21:35:45 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_img(t_game *g, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(g->mlx, path, &w, &h);
	if (!img)
	{
		ft_printf("Error\nFailed to load image: %s\n", path);
		ft_printf("Make sure the file exists and is a valid XPM file\n");
		free_map(g->map);
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		exit(1);
	}
	return (img);
}

void	find_player_position(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'P')
			{
				g->px = x;
				g->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	count_collectibles(t_game *g)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
