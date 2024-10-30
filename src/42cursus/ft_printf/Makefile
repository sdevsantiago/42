# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:07:42 by sede-san          #+#    #+#              #
#    Updated: 2024/10/30 19:19:28 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #
# Library name
NAME = libftprintf.a

# ************************** Compilation variables *************************** #
# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

# ****************************** Source files ******************************** #
SRC = \
ft_printf.c

# ****************************** Object files ******************************** #
OBJ = $(SRC:.c=.o)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************* Rules ************************************ #
# Compile all
all: $(NAME)

$(NAME): $(OBJ)
	cd Libft && make all bonus && mv ./libft.a ../libftprintf.a
	ar rcs $(NAME) $(OBJ)
	
# Clean object files
clean:
	cd Libft && make clean
	rm -f $(OBJ)

# Clean object files and library
fclean: clean
	cd Libft && make fclean
	rm -f $(NAME)
	rm -f $(OBJ)

# Recompile
re: fclean all

# *********************************** Phony ********************************** #
.PHONY = all clean fclean re