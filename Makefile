# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgaillar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 20:10:24 by jgaillar          #+#    #+#              #
#    Updated: 2018/05/01 10:53:41 by jgaillar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/

SRC_NAME = 	colorcontrols.c ft_segment.c keyhooks.c main.c malloc.c movmap.c \
			parseur.c struct.c controlhelp.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CPPFLAGS = -Iincludes

NAME = fdf

CC = clang

CCFLAGS = -Ofast -Wall -Wextra -Werror

FDFFLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft ; make re ; make clean ; cd ..
	@cd mlx ; make re ; cd ..
	$(CC) $(CCFLAGS) $(FDFFLAGS) $(CPPFLAGS) libft/libft.a mlx/libmlx.a $^ -o $@

clean:
	@cd src ; rm -rf $(OBJ_NAME) ; cd ..

fclean: clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean
