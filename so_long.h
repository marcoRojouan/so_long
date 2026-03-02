/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:49:49 by mrojouan          #+#    #+#             */
/*   Updated: 2026/03/02 15:19:11 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_game
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collect;
	void	*exit;
	int		tile_width;
	int		tile_height;
	char	**map;
	int		player_count;
	int		exit_count;
	int		consum_count;
	int		move_count;
	int		width;
	int		height;	
	int		player_y;
	int		player_x;
	void	*mlx;
	void	*window;
}	t_game;

int		ft_strnlen(char *str);
int		exit_window(t_game *game);
int		key_press(int keypress, t_game *game);
int		ft_strcmp(char *s1, char *s2);

void	change_last_char(char *line);
void	parsing(t_game *game, char *mapfile);
void	get_position(t_game *game);
void	send_current_tile(t_game *game);
void	flood_fill(char **tab, t_game *game, int player_y, int player_x);
void	init_game(t_game *game);
void	check_path(t_game *game);
void	map_filler(t_game *game, int map_fd);
void	handle_map_error(t_game *game, char *error);
void	verif_map(t_game *game);
void	free_tab(char **tab);

#endif