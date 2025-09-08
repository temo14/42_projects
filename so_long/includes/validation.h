/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:06:20 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/13 19:53:13 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "so_long.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		validate_map(char **map);

int		validate_walls_and_shape(char **map);
int		validate_elements(char **map);
int		validate_path(char **map);
char	**copy_map_for_flood(char **map);
int		flood_fill_check(char **map, int x, int y, int found[2]);

#endif
