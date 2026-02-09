/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:11:21 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/09 17:23:14 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static int get_map_size(t_map *map, int map_fd)
{
	char	*line;
	int		line_size;

	line = get_next_line(map_fd);
	if (!line)
		handle_map_error();
	map->map_size = 1;
	while (line)
	{	
		free(line);
		line = get_next_line(map_fd);
		map->map_size++;
	}
	free(line);
}

void map_filler(t_map *map, int map_fd)
{
	int	i;

	i = 0;
	map->map = malloc(sizeof(char *) * map->map_size + 1);
	map->map[i] = get_next_line(map_fd);
	if (!map->map[i])
		handle_map_error();
	i++;
	while (map->map[i])
	{
		map->map[i] = get_next_line(map_fd);
		i++;
	}
	map->map[i] = NULL;
}	
