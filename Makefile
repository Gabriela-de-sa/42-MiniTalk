# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 16:57:30 by gabriela          #+#    #+#              #
#    Updated: 2024/03/07 11:43:57 by gde-sa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#
SERVER = server
CLIENT = client
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

HEADERS = -I ./mandatory/include -I ./libft
LIBS = ./libft/libft.a

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#

S_FILE = mandatory/server.c
S_OBJS = $(S_FILE:.c=.o)

C_FILE = mandatory/client.c\
		 mandatory/ft_valid_args.c\

C_OBJS = $(C_FILE:.c=.o)
#******************************************************************************#
#				     				RULES      								   #
#******************************************************************************#

all: $(SERVER) $(CLIENT) 

$(LIBS):
	@make -sC ./libft

$(SERVER): $(S_OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(S_OBJS) $(HEADERS) $(LIBS) -o $(SERVER)

$(CLIENT): $(C_OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(C_OBJS) $(HEADERS) $(LIBS) -o $(CLIENT)

clean:
	@rm -rf $(S_OBJS) $(C_OBJS)
	@make clean -sC ./libft

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all, clean, fclean, re, bonus