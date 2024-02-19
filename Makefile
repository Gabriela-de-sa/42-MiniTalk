# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 16:57:30 by gabriela          #+#    #+#              #
#    Updated: 2024/02/19 17:53:22 by gabriela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#								  CONFIGURATION				       			   #
#******************************************************************************#
NAME_SERVER = server
NAME_CLIENT = client
CFLAGS = -g3 -Wall -Wextra -Werror

HEADERS = -I ./mandatory/include -I ./libft
LIBS = ./libft/libft.a

#******************************************************************************#
#				     				FILES      								   #
#******************************************************************************#

SRC = mandatory/

FILES = \
	

MANDATORY_FINAL = $(addprefix $(MANDATORY),$(FILES))

OBJS = $(MANDATORY_FINAL:.c=.o)

all: libft/libft.a $(NAME_CLIENT) $(NAME_SERVER)

libft/libft.a:
	@make -sC ./libft

clean:
	@rm -rf $(OBJS)
	@make clean -sC ./libft

fclean: clean
	@cd libft && $(MAKE) fclean
	@rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all, clean, fclean, re, bonus