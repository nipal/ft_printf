# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:28:32 by fjanoty           #+#    #+#              #
#    Updated: 2017/12/09 16:14:03 by fjanoty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all fclean re gdb

export CFLAGS	= -g  -Wall -Wextra -Werror -O2

export CC	= gcc


SRC_DIR			= ./src
LIB_FT			= ./libft

all:
	make -C $(LIB_FT)
	make -C $(SRC_DIR)
	

clean:
	make -C $(LIB_FT)  		clean
	make -C $(SRC_DIR) 		clean

fclean: clean
	make -C $(LIB_FT)		fclean
	make -C $(SRC_DIR)		fclean

re: fclean all
