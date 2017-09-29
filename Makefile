# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opariy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 13:07:08 by opariy            #+#    #+#              #
#    Updated: 2017/09/11 14:35:26 by opariy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
SOURCE = parsing.c gnl.c lists.c link.c path.c algorithm.c validation.c deal_with_list.c list_create.c function_set.c deal_with_matrix.c stupid_fucntions_find_path.c
OBJ = $(SOURCE:.c=.o)
HEADER = lem-in.h

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	gcc libft/libft.a $(OBJ) -I $(HEADER) -o ${NAME}

.c.o:
	gcc -Wall -Wextra -c -o $@ $<

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
