# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtari-ca <rtari-ca@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 18:14:18 by rtari-ca          #+#    #+#              #
#    Updated: 2024/10/08 20:03:43 by rtari-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
      ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memmove.c \
      ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
      ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
      ft_toupper.c ft_substr.c ft_strjoin.c ft_putendl_fd.c ft_putchar_fd.c \
      ft_putstr_fd.c ft_memcmp.c ft_calloc.c ft_putnbr_fd.c ft_itoa.c \
      ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
