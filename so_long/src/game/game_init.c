/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:42:52 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/18 20:17:26 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_sprites(t_game *g)
{
	g->img_player = load_img(g, "assets/sprites/marios/mario.xpm");
	g->img_wall = load_img(g, "assets/sprites/square.xpm");
	g->img_floor = load_img(g, "assets/sprites/wall.xpm");
	g->img_exit = load_img(g, "assets/sprites/door.xpm");
	g->img_collect = load_img(g, "assets/sprites/coin.xpm");
}

static void	init_window(t_game *g)
{
	g->win = mlx_new_window(g->mlx, g->width * TILE_SIZE, g->height * TILE_SIZE,
			"so_long");
	if (!g->win)
	{
		ft_printf("Error\nFailed to create window\n");
		free_map(g->map);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		exit(1);
	}
}

static void	check_width(t_game *g)
{
	if (!g->map)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		exit(1);
	}
}

void	game_init(t_game *g, char *map_path)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		ft_printf("Error\nFailed to initialize MLX\n");
		exit(1);
	}
	g->map = read_map(map_path);
	if (!g->map)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		exit(1);
	}
	validate_map(g->map);
	g->height = map_height(g->map);
	g->width = map_width(g->map);
	check_width(g);
	g->moves = 0;
	find_player_position(g);
	g->collectibles = count_collectibles(g);
	init_window(g);
	load_sprites(g);
	render_map(g);
	ft_printf("Game initialized!\n");
	ft_printf("Moves: %d | Collectibles: %d\n", g->moves, g->collectibles);
}
