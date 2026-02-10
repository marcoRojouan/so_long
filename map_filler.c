/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:11:21 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/10 15:49:33 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static void get_map_size(t_map *map)
{
	char	*line;
	int		tmp_map_fd;

	tmp_map_fd = open("map.ber", O_RDONLY);
	line = get_next_line(tmp_map_fd);
	if (!line)
	{
		printf(" pas 1 okay \n");
		handle_map_error();
	}
	map->width = ft_strnlen(line);
	while (line)
	{	
		free(line);
		line = get_next_line(tmp_map_fd);
		map->height++;
	}
	free(line);
	close(tmp_map_fd);
}

void map_filler(t_map *map, int map_fd)
{
	int	i;

	i = 0;
	get_map_size(map);
	map->map = malloc(sizeof(char *) * map->height + 1);
	map->map[i] = get_next_line(map_fd);
	if (!map->map[i])
	{
		printf(" pas 2 okay \n");
		handle_map_error();
	}
	i++;
	while (i < map->height)
	{
		map->map[i] = get_next_line(map_fd);
		i++;
	}
	map->map[i] = NULL;
}	
