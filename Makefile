# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:19:44 by juhur             #+#    #+#              #
#    Updated: 2022/02/14 10:53:29 by juhur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJS = $(addsuffix .o, $(CLIENT) $(SERVER))

all : $(CLIENT) $(SERVER)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(CLIENT)
	rm -rf $(SERVER)

re : fclean all

.PHONY : all, clean, fclean, re

$(CLIENT) : client.c
	$(CC) $(CFLAGS) $< -o $@

$(SERVER) : server.c
	$(CC) $(CFLAGS) $< -o $@