#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin  <jgeslin@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/15 12:36:55 by jgeslin           #+#    #+#              #
#    Updated: 2016/10/04 15:23:30 by gvilmont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./srcs/main.c ./srcs/ft_mandelbrot.c ./srcs/ft_julia.c\
	  ./srcs/ft_init.c ./srcs/ft_do.c ./srcs/ft_mandelbis.c\
	  ./srcs/ft_menu.c ./srcs/ft_mandelpow.c ./srcs/ft_power.c\

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
