# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:22:54 by fnieves-          #+#    #+#              #
#    Updated: 2022/08/22 16:35:42 by fnieves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# define the compiler to be used
CC	= cc
# define the compiler flags
FLAGS = -Wall -Wextra -Werror
# define the c files that this project needs
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putnbr_fd.c ft_putendl_fd.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_strncmp_uplo.c \
ft_atof.c ft_isspace.c ft_strisfloat.c ft_pow.c
#define the sourcefiles that the bonuspart needs
BSRC = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c \
ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c
#define the objectfiles that the project needs
OBJ = $(SRC:.c=.o)
#define the objectfiles that the bonuspart needs
BONUSOBJ = $(BSRC:.c=.o)
#define the header
HEADER = libft.h
# define the name of the library you want to produce
NAME = libft.a

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUSOBJ) $(OBJ)
	@ar rc $(NAME) $(BONUSOBJ) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
