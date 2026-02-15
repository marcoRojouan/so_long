# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 14:47:39 by mrojouan          #+#    #+#              #
#    Updated: 2026/02/15 17:09:23 by mrojouan         ###   ########.fr        #
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
		parsing_helper/get_position.c

GNL_SRC	= get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c

OBJ_DIR	= obj
OBJ		= $(SRC:%.c=$(OBJ_DIR)/%.o)
GNL_OBJ = $(GNL_SRC:%.c=$(OBJ_DIR)/%.o)

CC		= cc
FLAGS	= -Wall -Werror -Wextra

MLX_DIR	= mlx
MLX_LIB	= $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(MLX_LIB)
	$(CC) $(FLAGS) $^ -Lmlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -Imlx -Iincludes -c $< -o $@

$(OBJ_DIR)/parsing_helper/%.o: parsing_helper/%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

