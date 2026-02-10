/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:49:49 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/10 15:07:56 by mrojouan         ###   ########.fr       */
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

int 	parsing();
int 	ft_strnlen(char *str);

void 	map_filler(t_map *map, int map_fd);
void	handle_map_error(void);
void	verif_map(t_map *map);

#endif
