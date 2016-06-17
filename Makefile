#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin  <jgeslin@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 12:36:55 by jgeslin           #+#    #+#              #
#    Updated: 2016/06/17 17:40:11 by gvilmont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./srcs/main.c ./srcs/ft_mandelbrot.c ./srcs/ft_julia.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBS = libft/libft.a

GNL = libft/sources/get_next_line.c

FLAGMLX = -lmlx -framework Opengl -framework AppKit

all: $(NAME)

$(NAME):$(OBJ)
			gcc $(FLAG) -o $(NAME) $(FLAGMLX) $(GNL) $(SRC) $(LIBS) -I.

clean:
			/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re:fclean all	

.PHONY: clean fclean re all
