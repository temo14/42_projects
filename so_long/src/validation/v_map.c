/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:49:49 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/13 19:49:50 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char **map)
{
	if (!map)
		return (0);
	if (!validate_walls_and_shape(map))
		return (0);
	if (!validate_elements(map))
		return (0);
	if (!validate_path(map))
		return (0);
	return (1);
}
