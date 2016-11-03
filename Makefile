# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaitalla <yaitalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/30 01:29:56 by yaitalla          #+#    #+#              #
#    Updated: 2015/04/15 23:03:36 by yaitalla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CFLAGS=-Werror -Wextra -Wall -Ilibft/includes
LFLAGS=-Llibft -lft
SRC= main.c error.c setup.c moves.c free.c action.c file.c push_swap.c
OBJ=$(SRC:.c=.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^ $(LFLAGS)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

lib:
	make -C libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all
