NAME = libftprintf.a

SRC = ft_printf.c \
      ft_printf_chars.c \
	  ft_printf_numbers.c \
	  ft_printf_pointer.c \
	  ft_printf_hex.c  \

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_LIB) ./
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# test: 
# 	cc main.c $(NAME)
# 	./a.out

re: fclean all

