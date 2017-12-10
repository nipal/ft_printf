# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:32:20 by fjanoty           #+#    #+#              #
#    Updated: 2017/12/09 16:14:08 by fjanoty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all fclean re

#-fsanitize=address -g3
NAME	=	../ft_printf
DEPS =  ../inc/ft_printf.h

SRC		= 		main_test.c					\

OBJ			= $(SRC:.c=.o)


LIB_DIR		= -L ../libft 


LIB_NAME	= -lft -lm



all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME)  $(OBJ)  $(LIB_DIR) $(LIB_NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< -I ../inc 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
