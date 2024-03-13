# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 16:57:30 by gabriela          #+#    #+#              #
#    Updated: 2024/03/12 21:54:22 by gabriela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror

HEADERS = -I ./mandatory/include -I ./libft
HEADERS_BONUS = -I ./bonus/include_bonus -I ./libft
LIBS = ./libft/libft.a

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#

S_FILE = mandatory/server.c
S_OBJS = $(S_FILE:.c=.o)

C_FILE = mandatory/client.c\
		 mandatory/ft_valid_args.c
C_OBJS = $(C_FILE:.c=.o)

S_FILE_BONUS = bonus/server_bonus.c
S_OBJS_BONUS = $(S_FILE_BONUS:.c=.o)

C_FILE_BONUS = bonus/client_bonus.c\
		 	   bonus/ft_valid_args_bonus.c
C_OBJS_BONUS = $(C_FILE_BONUS:.c=.o)
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

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(S_OBJS_BONUS) $(LIBS)
	$(CC) $(CFLAGS) $(S_OBJS_BONUS) $(HEADERS_BONUS) $(LIBS) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(C_OBJS_BONUS) $(LIBS)
	$(CC) $(CFLAGS) $(C_OBJS_BONUS) $(HEADERS_BONUS) $(LIBS) -o $(CLIENT_BONUS)

clean:
	@rm -rf $(S_OBJS) $(C_OBJS) $(S_OBJS_BONUS) $(C_OBJS_BONUS)
	@make clean -sC ./libft

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re, bonus