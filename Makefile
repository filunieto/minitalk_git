# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnieves <fnieves@42heilbronn.de>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/20 07:06:40 by fnieves           #+#    #+#              #
#    Updated: 2022/08/20 07:25:01 by fnieves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src
INCFLAGS = -I include

CC		= cc
CFLAGS	=  -Wall -Werror -Wextra
RM = rm -f
FILE_PATH = ./


SERVER = server
CLIENT = client

SERVER_FILES = server.c
CLIENT_FILES = client.c

HEADER	= 	include/mini_talk.h

SERVER_FILES = server.c
CLIENT_FILES = client.c

SERVER_OBJS = $(addprefix $(FILE_PATH), $(addsuffix .o, $(SERVER)))
CLIENT_OBJS = $(addprefix $(FILE_PATH), $(addsuffix .o, $(CLIENT)))

all: $(SERVER) $(CLIENT) 

$(SERVER): ft_minitalk.h $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT): ft_minitalk.h $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

# $(SERVER_BONUS): $(BONUS_PATH)ft_minitalk_bonus.h $(FT_PRINTF_OBJ) $(SERVER_BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJS) $(FT_PRINTF_OBJ) -o $(SERVER_BONUS)

# $(CLIENT_BONUS): $(BONUS_PATH)ft_minitalk_bonus.h $(FT_PRINTF_OBJ) $(CLIENT_BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(FT_PRINTF_OBJ) -o $(CLIENT_BONUS)

# bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: clean fclean re ft_printf all bonus
