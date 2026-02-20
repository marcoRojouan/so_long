# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 14:47:39 by mrojouan          #+#    #+#              #
#    Updated: 2026/02/18 14:00:56 by mrojouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= so_long.c \
		parsing_helper/parsing.c \
		parsing_helper/errors.c \
		parsing_helper/utils.c \
		parsing_helper/verif.c \
		parsing_helper/map_filler.c \
		parsing_helper/check_path.c \
		parsing_helper/flood_fill.c \
		parsing_helper/get_position.c \
		game/init_game.c

GNL_SRC	= get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c

OBJ_DIR	= obj
OBJ		= $(SRC:%.c=$(OBJ_DIR)/%.o)
GNL_OBJ = $(GNL_SRC:%.c=$(OBJ_DIR)/%.o)

CC		= cc
FLAGS	= -Wall -Werror -Wextra -g

MLX_DIR	= mlx
MLX_LIB	= $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(MLX_LIB)
	$(CC) $(FLAGS) $^ -Lmlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)


# Compilation générique pour tous les .c (racine, parsing_helper, game, get_next_line)
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -Imlx -I. -Iget_next_line -c $< -o $@

$(OBJ_DIR)/parsing_helper/%.o: parsing_helper/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -Imlx -I. -Iget_next_line -c $< -o $@

$(OBJ_DIR)/game/%.o: game/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -Imlx -I. -Iget_next_line -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: get_next_line/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -Imlx -I. -Iget_next_line -c $< -o $@
PHONY: all clean fclean re

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

