# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:19:44 by juhur             #+#    #+#              #
#    Updated: 2022/02/14 13:28:49 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

clean :
	rm -rf $(CLIENT)
	rm -rf $(SERVER)

fclean : clean

re : fclean all

.PHONY : all, clean, fclean, re

$(NAME) : $(CLIENT) $(SERVER)

$(CLIENT) : client.c
	$(CC) $(CFLAGS) $< -o $@

$(SERVER) : server.c
	$(CC) $(CFLAGS) $< -o $@