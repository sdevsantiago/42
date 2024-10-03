# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 14:21:55 by sede-san          #+#    #+#              #
#    Updated: 2024/10/03 08:43:31 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************** Output file ******************************* #
NAME =		libft.a

# ********************************* Variables ******************************** #
# Compiler and flags
CC =		cc
CFLAGS =	-Wall -Wextra -Werror

# Debug flags
DFLAGS =	-g3 -fsanitize=address
ifdef DEBUG
	CFLAGS += $(DFLAGS)
endif

# ******************************* Source file********************************* #
# Mandatory part 1
SRC_MP1= \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c

# Mandatory part 2
SRC_MP2= \
	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strtrim.c \
	ft_substr.c

# Bonus part
SRC_B= \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c

# Additional functions
SRC_A= \
	ft_isspace.c \
	ft_putchar.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_strncpy.c

# ********************************* Objects ********************************** #
# Mandatory part 1
OBJ_MP1 =	$(SRC_MP1:.c=.o)

# Mandatory part 2
OBJ_MP2 =	$(SRC_MP2:.c=.o)

# Bonus part
OBJ_B =		$(SRC_B:.c=.o)

# Additional functions
OBJ_A =		$(SRC_A:.c=.o)

# Compile objects
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************* Rules ************************************ #
# Compile all
all: $(NAME)

$(NAME): $(OBJ_MP1) $(OBJ_MP2) $(OBJ_A)
	ar rcs $(NAME) $(OBJ_MP1) $(OBJ_MP2) $(OBJ_A)

# Compile bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME):
	AR rcs $(NAME) $(OBJ_B)
# Clean objects
clean:
	rm -f $(OBJ_MP1) $(OBJ_MP2) $(OBJ_A)

# Clean objects and executable
fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ_B)

# Clean all and recompile
re: fclean all

# ********************************* Phony ************************************ #
.PHONY = all bonus clean fclean re