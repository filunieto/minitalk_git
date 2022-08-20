# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 12:38:38 by hoomen            #+#    #+#              #
#    Updated: 2022/07/06 21:11:19 by hoomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH	= src bonus
INCFLAGS = -I libft -I ftprintf -I mlx -I include

CC		= cc
FLAGS	= -Wall -Werror -Wextra

NAME	= fractol
BONUSNAME = fractol
HEADER	= include/fractol.h include/fr_userinfo.h include/keys.h include/fractol_bonus.h
SRC		= main.c parse.c parse_julia.c init.c fractals.c complex.c newtons_utils.c color.c hsv2rgb.c events.c view.c change_image.c print_info.c print_info2.c
BON		= main_bonus.c parse.c parse_julia.c init.c fractals.c complex.c newtons_utils.c color.c hsv2rgb.c events.c view.c change_image.c print_info.c print_info2.c
LIBS	= libft/libft.a ftprintf/libftprintf.a
OBJ		= $(addprefix obj/,$(notdir $(SRC:.c=.o)))
BONOBJ	= $(addprefix obj/,$(notdir $(BON:.c=.o)))

$(NAME) : $(OBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $@ $^ -Llibft -lft -Lftprintf -lftprintf -lm -Lmlx -lmlx -framework OpenGL -framework AppKit

obj/%.o : %.c $(LIBS) $(HEADER) | obj
	$(CC) $(FLAGS) $(INCFLAGS) -c $< -o $@

obj :
	mkdir obj

$(LIBS) :
	-(cd libft && make)
	-(cd ftprintf && make && make clean)
	-(cd libft && make clean)

all : $(NAME)

bonus : $(BONOBJ) | $(LIBS)
	$(CC) $(FLAGS) -o $(NAME) $^ -Llibft -lft -Lftprintf -lftprintf -lm -Lmlx -lmlx -framework OpenGL -framework AppKit

clean :
	rm -rf obj
	
fclean : clean
	rm -f $(NAME)
	-(cd libft && make fclean)
	-(cd ftprintf && make fclean)

re : clean all

libs : fclean all

.PHONY : all clean fclean re bonus

