/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/12 14:23:17 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <so_long.h>

int parsing(void)
{
	int		map_fd;
	t_map	map;

	map.map = NULL;
	map.height = 0;
	map.width = 0;
	map.consum_count = 0;
	map.exit_count = 0;
	map.player_count = 0;
	map_fd = open("map.ber", O_RDONLY);
	if (map_fd < 0)
		handle_map_error(&map);
	map_filler(&map, map_fd);
	verif_map(&map);
	free_tab(map.map);
	close(map_fd);
	return (1);
}
