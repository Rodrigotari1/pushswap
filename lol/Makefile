# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 19:02:38 by rodrigo           #+#    #+#              #
#    Updated: 2025/01/08 21:04:41 by rodrigo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT_DIR = libft
LIBFT = ./libft/libft.a
RM = rm -rf

SRCS = push_swap.c \
       stack_operations.c \
       sort_tiny.c \
       bucket_sort.c \
       stack_init.c \
       stack_init_utils.c \
       stack_validation.c \
       stack_helpers.c

SRC = $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)
INC = -I./inc

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "\033[1;34mCompiling Libft...\033[0m"
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	@echo "\033[1;32mCompiling Push Swap...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft
	@echo "\033[1;36m              _____ _______             \033[0m"
	@echo "\033[1;36m             |  __ \\__   __|            \033[0m"
	@echo "\033[1;36m             | |__) | | |               \033[0m"
	@echo "\033[1;36m             |  _  /  | |               \033[0m"
	@echo "\033[1;36m             | | \\ \\  | |               \033[0m"
	@echo "\033[1;36m             |_|  \\_\\ |_|               \033[0m"
	@echo "\033[1;32mYour Push Swap is ready to roll!\033[0m"

$(OBJ): $(SRC)
	@echo "\033[1;33mCompiling source files...\033[0m"
	@$(CC) $(CFLAGS) -c $(SRC) $(INC)
	@mv *.o src

clean:
	@echo "\033[1;31mCleaning object files...\033[0m"
	@$(RM) src/*.o
	@make -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[1;31mRemoving executable...\033[0m"
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
