# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 15:22:54 by hoomen            #+#    #+#              #
#    Updated: 2022/07/04 13:04:05 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler variables
CC		=	cc
FLAGS 	=	-Wall -Wextra -Werror
# file variables
NAME	= libftprintf.a
MAIN	= printf initmodifiers parse modifiers convert printchar pad printstr printint printnbr putnbrpf printfloat
LIBFT	= isdigit strlen strchr
HEADER	= ft_printf.h
MAINFILES	= $(addprefix ft_,$(addsuffix .c, $(MAIN)))
LIBFTFILES	= $(addprefix ../libft/ft_,$(addsuffix .c, $(LIBFT)))
MAINOBJS	= $(MAINFILES:.c=.o)
LIBFTOBJS	= $(LIBFTFILES:.c=.o)

all : $(NAME) clean

$(NAME): $(MAINOBJS) $(LIBFTOBJS)
	@ar rc $(NAME) $(MAINOBJS) $(LIBFTOBJS)

%.o: %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f libft/*.o

bonus: re

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
