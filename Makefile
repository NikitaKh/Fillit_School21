# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 17:10:51 by cgoliath          #+#    #+#              #
#    Updated: 2019/11/30 21:13:12 by cgoliath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = ft_begin.c check_valid.c get_next_line.c main.c solve.c  map_functions.c

OBJ = $(SRC:.c=.o)

HDR = header.h

LIBFT = libft/

all: $(NAME)

$(NAME): $(OBJ)
				make -C $(LIBFT)
				gcc $(FLAGS) -o $(NAME) $(SRC) -I $(HDR) -L. libft/libft.a

$(OBJ): %.o : %.c
			gcc $(FLAGS) -c $<

clean: 
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
