# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 01:28:32 by fjanoty           #+#    #+#              #
#    Updated: 2018/01/11 20:58:05 by fjanoty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all fclean re gdb

LIB1		=  ./libft

SRC_PATH 	= src
SRC_NAME 	= 						\
				main_test.c			\
				bistromatique.c		\
				integer.c			\
				type_function.c		\
				print.c				\
				print_bit.c			\
				parsing.c			\
				pars_func.c			\
				precision_func.c	\
				print_function.c	\
				floating_number.c	\



OBJ_PATH	= 	obj
CPPFLAGS 	= 	-I inc -I $(LIB1)
LDLIBS 		= 	-lft
LDFLAGS 	= 	-L $(LIB1)  $(LDLIBS)
NAME 		= 	ft_printf
CC			= 	gcc

CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+= 	-g3 -fsanitize=address
#CFLAGS		+=	-02
OBJ_NAME 	= 	$(SRC_NAME:.c=.o)

SRC 		= 	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
#OBJ 		= 	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ			= 	$(SRC:.c=.o)
	
all: $(NAME)

LIB1:
	make -C $(LIB1)

$(NAME): $(OBJ)
	    $(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	    @mkdir -p $(OBJ_PATH)
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	rm  -rf $(OBJ_PATH)

#	make -C $(LIB1) clean

fclean: clean

re: fclean all

#	make -C $(LIB1) re

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

