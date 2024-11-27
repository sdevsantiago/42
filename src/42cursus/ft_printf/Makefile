# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:07:42 by sede-san          #+#    #+#              #
#    Updated: 2024/11/27 20:00:22 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #
# Library name
NAME = ft_printf.a

# ************************** Compilation variables *************************** #
# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

# ****************************** Source files ******************************** #
SRC = \
ft_printf.c

CHARACTER_STRING_PATH = character_string_types

SRC += \
$(CHARACTER_STRING_PATH)/ft_printf_putchar.c \
$(CHARACTER_STRING_PATH)/ft_printf_putstr.c

INTEGER_PATH = integer_types

SRC += \
$(INTEGER_PATH)/ft_printf_putint.c	\
$(INTEGER_PATH)/ft_printf_putuint.c

MEMDIR_PATH = memdir_types

SRC += \
$(MEMDIR_PATH)/ft_printf_putptr.c

# ****************************** Object files ******************************** #
OBJ = $(SRC:.c=.o)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************* Rules ************************************ #
# Compile all
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C Libft all bonus
	cp Libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	mv $(NAME) libftprintf.a

# Clean object files
clean:
	cd Libft && $(MAKE) clean
	rm -f $(OBJ)

# Clean object files and library
fclean: clean
	cd Libft && $(MAKE) fclean
	rm -f libftprintf.a
	rm -f $(OBJ)

# Recompile
re: fclean all

# *********************************** Phony ********************************** #
.PHONY = all clean fclean re