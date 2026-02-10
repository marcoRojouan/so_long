# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/08 14:47:39 by mrojouan          #+#    #+#              #
#    Updated: 2026/02/10 15:15:36 by mrojouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= so_long.c \
		  parsing.c \
		  errors.c	\
		  utils.c	\
		  verif.c	\
		  map_filler.c	

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

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

