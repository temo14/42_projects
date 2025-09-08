# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbaindur <tbaindur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 19:43:16 by tbaindur          #+#    #+#              #
#    Updated: 2025/07/22 20:01:11 by tbaindur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes

SRC_DIR = .
OBJ_DIR = obj
MAIN_DIR = main
OPERATIONS_DIR = operations
PARSING_DIR = parsing
SORTING_DIR = sorting
STACK_DIR = stack
UTILS_DIR = utils

MAIN_SRC = main/push_swap.c

OPERATIONS_SRC = operations/op_push.c \
				 operations/op_rev_rotate.c \
				 operations/op_rotate.c \
				 operations/op_swap.c

PARSING_SRC = parsing/parse.c

SORTING_SRC = sorting/indexing.c \
			  sorting/quick_sort.c \
			  sorting/radix_sort.c \
			  sorting/sort_small.c

STACK_SRC = stack/stack_operation.c

UTILS_SRC = utils/ft_split_utils.c \
			utils/libft_utils.c \
			utils/utility.c

SRCS = $(MAIN_SRC) $(OPERATIONS_SRC) $(PARSING_SRC) $(SORTING_SRC) $(STACK_SRC) $(UTILS_SRC)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "$(BLUE)Running basic tests...$(NC)"
	@./$(NAME) 4 67 3 87 23

test_error: $(NAME)
	@echo "$(BLUE)Testing error cases...$(NC)"
	@./$(NAME) 42 42 || true
	@./$(NAME) abc || true
	@./$(NAME) || true

check: $(NAME)
	@if [ -f ./checker_linux ]; then \
		echo "$(BLUE)Testing with checker...$(NC)"; \
		ARG="4 67 3 87 23"; ./$(NAME) $$ARG | ./checker_linux $$ARG; \
	else \
		echo "$(YELLOW)checker_linux not found, skipping checker test$(NC)"; \
	fi

debug: CFLAGS += -DDEBUG -fsanitize=address
debug: re

norm:
	@if command -v norminette > /dev/null 2>&1; then \
		echo "$(BLUE)Checking norm...$(NC)"; \
		norminette $(SRCS) includes/push_swap.h; \
	else \
		echo "$(YELLOW)norminette not found, skipping norm check$(NC)"; \
	fi

.PHONY: all clean fclean re bonus test test_error check debug norm
