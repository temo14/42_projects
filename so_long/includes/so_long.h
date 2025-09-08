/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:55:03 by tbaindur          #+#    #+#             */
/*   Updated: 2025/08/18 20:01:43 by tbaindur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_HEIGHT 20
# define MAX_WIDTH 40
# define TILE_SIZE 64
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# include "../assets/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_collect;
	int		width;
	int		height;
	int		px;
	int		py;
	int		collectibles;
	int		moves;
}			t_game;

int			ft_printf(const char *format, ...);
char		*get_next_line(int fd);

void		game_init(t_game *g, char *map_path);
void		*load_img(t_game *g, char *path);
void		render_map(t_game *g);
int			key_hook(int keycode, t_game *g);
int			close_hook(t_game *g);
void		move_player(t_game *g, int new_x, int new_y);
void		find_player_position(t_game *g);
int			count_collectibles(t_game *g);
int			key_hook(int keycode, t_game *g);
int			close_hook(t_game *g);
void		handle_right(t_game *g, int *frame_right);
void		handle_left(t_game *g, int *frame_left);
void		handle_down(t_game *g, int *frame_down);
void		handle_up(t_game *g, int *frame_up);

char		**read_map(char *map_address);
char		**read_map_lines(int fd, char **map, int i);
char		**validate_map_result(char **map, int line_count);
char		*process_line(char *line);
char		**allocate_map(void);
int			map_height(char **map);
int			map_width(char **map);
void		free_map(char **map);

int			validate_map(char **map);
int			validate_walls_and_shape(char **map);
int			validate_elements(char **map);
int			validate_path(char **map);

#endif
