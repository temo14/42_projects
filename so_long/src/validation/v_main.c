/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 22:09:27 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/14 21:04:25 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "validation.h"

int	validate_map(char **map)
{
	if (!map)
	{
		ft_printf("Error\nInvalid map (null)\n");
		exit(EXIT_FAILURE);
	}
	if (!validate_walls_and_shape(map))
	{
		ft_printf("Error\nInvalid map format, walls, or shape\n");
		exit(EXIT_FAILURE);
	}
	if (!validate_elements(map))
	{
		ft_printf("Error\nMap must have exactly 1 player, 1 exit\n");
		exit(EXIT_FAILURE);
	}
	if (!validate_path(map))
	{
		ft_printf("Error\nNo valid path to all collectibles and exit\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}
