/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:25:56 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/17 20:01:31 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_hook(t_game *g)
{
	free_map(g->map);
	if (g->img_collect)
		mlx_destroy_image(g->mlx, g->img_collect);
	if (g->img_exit)
		mlx_destroy_image(g->mlx, g->img_exit);
	if (g->img_floor)
		mlx_destroy_image(g->mlx, g->img_floor);
	if (g->img_player)
		mlx_destroy_image(g->mlx, g->img_player);
	if (g->img_wall)
		mlx_destroy_image(g->mlx, g->img_wall);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(0);
}

int	key_hook(int keycode, t_game *g)
{
	static int	frame_up = 0;
	static int	frame_down = 0;
	static int	frame_left = 0;
	static int	frame_right = 0;

	if (keycode == KEY_ESC)
		close_hook(g);
	else if (keycode == KEY_W || keycode == KEY_UP)
		handle_up(g, &frame_up);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		handle_down(g, &frame_down);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		handle_left(g, &frame_left);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		handle_right(g, &frame_right);
	return (0);
}
