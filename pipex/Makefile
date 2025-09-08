NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g

SRC = main.c src/pipex.c src/pipex_utils.c src/pipex_path.c
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
