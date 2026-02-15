/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:49:49 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/15 17:00:32 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
	int		player_count;
	int		exit_count;
	int		consum_count;
	int		width;
	int		height;
} 				t_map;

typedef struct s_position
{
	int player_y;
	int player_x;
}				t_position;

int 	parsing();
int 	ft_strnlen(char *str);

char	*ft_strdup(char *s);

void	get_position(t_map *map, t_position *position);
void	flood_fill(char **tab, t_map *map, int player_y, int player_x);
void 	map_filler(t_map *map, int map_fd);
void	handle_map_error(t_map *map);
void	verif_map(t_map *map);
void 	free_tab(char **tab);

#endif
