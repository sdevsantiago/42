# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 14:21:55 by sede-san          #+#    #+#              #
#    Updated: 2024/09/30 19:51:09 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC_M = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_itoa.c \
ft_strjoin.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memchr.c \
ft_memmove.c \
ft_memset.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_substr.c \
ft_putchar.c

OBJ_M = $(SRC_M:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M)
	ar rcs $(NAME) $(OBJ_M)
	ranlib $(NAME)

clean:
	rm -f $(OBJ_M)

fclean: clean
	rm -f $(NAME)	

re: fclean all

.PHONY = all clean fclean re
