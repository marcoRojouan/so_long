/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/15 16:01:11 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <so_long.h>

static void	initialise_map(t_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	map->consum_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
}

static void	initialise_pos(t_position *position)
{
	position->player_x = 0;
	position->player_y = 0;
}

int parsing(void)
{
	int		map_fd;
	t_position position;
	t_map	map;

	initialise_map(&map);
	initialise_pos(&position);
	map_fd = open("map.ber", O_RDONLY);
	if (map_fd < 0)
		handle_map_error(&map);
	map_filler(&map, map_fd);
	verif_map(&map);
	get_position(&map, &position);
	check_path(&map, &position);
	free_tab(map.map);
	close(map_fd);
	return (1);
}
