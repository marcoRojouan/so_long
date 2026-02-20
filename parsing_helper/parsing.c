/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/19 11:44:28 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <so_long.h>

void parsing(t_map *map, t_position *position)
{
	int		map_fd;
	
	map_fd = open("map.ber", O_RDONLY);
	if (map_fd < 0)
		handle_map_error(map);
	map_filler(map, map_fd);
	verif_map(map);
	get_position(map, position);
	check_path(map, position);
	close(map_fd);
}
