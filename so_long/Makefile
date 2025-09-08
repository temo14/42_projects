NAME = so_long

SRCS = src/main.c \
	   src/map/map_read.c \
   	   src/map/map_utils.c \
	   src/game/game_init.c \
   	   src/game/game_utils.c \
	   src/game/render.c \
   	   src/game/hooks.c \
   	   src/game/movement.c \
	   src/validation/v_main.c \
	   src/validation/v_map_shape.c \
   	   src/validation/v_map_path.c \
	   src/validation/v_map_elements.c 

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

MLXDIR = ./assets/minilibx-linux
MLXFILE = $(MLXDIR)/libmlx.a
PRINTF = assets/libftprintf.a
GNL = assets/get_next_line.a

$(NAME): mlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ${GNL} ${PRINTF} -lX11 -lXext -lm -lz -lpthread ${MLXFILE}

mlx:
	@if [ ! -d "$(MLXDIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git ${MLXDIR}; \
	fi
	make -C ${MLXDIR}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -fr $(MLXDIR)

re: fclean mlx all

.PHONY: all clean fclean re