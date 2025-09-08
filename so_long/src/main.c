/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:42:57 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/15 19:36:37 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_extension(char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i])
		i++;
	if (i < 5)
	{
		ft_printf("Error\nmap's extension is not correct\nexample: <.ber>\n");
		exit(1);
	}
	if (map_path[i - 4] != '.' || map_path[i - 3] != 'b' || map_path[i
			- 2] != 'e' || map_path[i - 1] != 'r')
	{
		ft_printf("Error\nmap's extension is not correct\nexample: <.ber>\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_game	g;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map.ber>\n");
		return (1);
	}
	check_map_extension(argv[1]);
	game_init(&g, argv[1]);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_hook(g.win, 17, 0, close_hook, &g);
	mlx_loop(g.mlx);
	return (0);
}
