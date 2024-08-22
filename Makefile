# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 14:59:39 by fmalungo          #+#    #+#              #
#    Updated: 2024/08/13 14:59:42 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -L/mlx/lib -Imlx -lXext -lX11 -lm -lz

SRC = so_long.c map_validations/map_reader.c	map_validations/map_utils.c \
		map_validations/traverse_map.c so_long_utils/split.c so_long_utils/errors.c\
		so_long_utils/window_game.c so_long_utils/move.c\

MLX = ./mlx

PRINTF = ./printf

RM = rm -rf

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/mlx -Imlx -O3 -c $< -o $@

all:  minilib printf $(NAME)

minilib:
	make -C mlx

printf:
	make -C printf

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) printf/libftprintf.a -o $(NAME)

clean:
	$(MAKE) clean -C ./mlx
	$(MAKE) clean -C ./printf
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./so_long "maps/map_v1.ber"
leak: all
	valgrind --leak-check=full -s ./so_long "maps/map_v1.ber"

.PHONY:	all clean fclean re