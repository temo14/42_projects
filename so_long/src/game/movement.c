/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:24:40 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/18 20:12:15 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *g, int new_x, int new_y)
{
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
	{
		g->collectibles--;
		g->map[new_y][new_x] = '0';
	}
	if (g->map[new_y][new_x] == 'E' && g->collectibles == 0)
	{
		ft_printf("Congratulations! You won in %d moves!\n", g->moves + 1);
		close_hook(g);
	}
	else if (g->map[new_y][new_x] == 'E' && g->collectibles > 0)
	{
		ft_printf("Collect all items first! Remaining: %d\n", g->collectibles);
		return ;
	}
	g->map[g->py][g->px] = '0';
	g->px = new_x;
	g->py = new_y;
	g->map[g->py][g->px] = 'P';
	g->moves++;
	ft_printf("Moves: %d | Collectibles remaining: %d\n", g->moves,
		g->collectibles);
	render_map(g);
}

void	handle_up(t_game *g, int *frame_up)
{
	static char	*frames[3] = {"assets/sprites/marios/mario9.xpm",
		"assets/sprites/marios/mario10.xpm",
		"assets/sprites/marios/mario11.xpm"};

	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	g->img_player = load_img(g, frames[*frame_up]);
	*frame_up = (*frame_up + 1) % 3;
	move_player(g, g->px, g->py - 1);
}

void	handle_down(t_game *g, int *frame_down)
{
	static char	*frames[3] = {"assets/sprites/marios/mario.xpm",
		"assets/sprites/marios/mario1.xpm",
		"assets/sprites/marios/mario2.xpm"};

	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	g->img_player = load_img(g, frames[*frame_down]);
	*frame_down = (*frame_down + 1) % 3;
	move_player(g, g->px, g->py + 1);
}

void	handle_left(t_game *g, int *frame_left)
{
	static char	*frames[3] = {"assets/sprites/marios/mario3.xpm",
		"assets/sprites/marios/mario4.xpm",
		"assets/sprites/marios/mario5.xpm"};

	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	g->img_player = load_img(g, frames[*frame_left]);
	*frame_left = (*frame_left + 1) % 3;
	move_player(g, g->px - 1, g->py);
}

void	handle_right(t_game *g, int *frame_right)
{
	static char	*frames[3] = {"assets/sprites/marios/mario6.xpm",
		"assets/sprites/marios/mario7.xpm",
		"assets/sprites/marios/mario8.xpm"};

	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	g->img_player = load_img(g, frames[*frame_right]);
	*frame_right = (*frame_right + 1) % 3;
	move_player(g, g->px + 1, g->py);
}
