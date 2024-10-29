# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 19:07:42 by sede-san          #+#    #+#              #
#    Updated: 2024/10/29 19:12:30 by sede-san         ###   ########.fr        #
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


# ********************************* Rules ************************************ #
# Compile all
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
# Clean object files
clean:
	rm -f ($OBJ)

# Clean bonus and library
fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f $(OBJ_B)

# Recompile
re: fclean all

# *********************************** Phony ********************************** #
.PHONY = all clean fclean re