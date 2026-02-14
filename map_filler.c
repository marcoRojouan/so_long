/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:11:21 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/13 14:10:28 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static void change_last_char(char *line)
{
	int len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	 	line[len - 1] = '\0';
}

static void get_map_size(t_map *map)
{
	char	*line;
	int		tmp_map_fd;

	tmp_map_fd = open("map.ber", O_RDONLY);
	if (tmp_map_fd < 0)
		handle_map_error(map);
	line = get_next_line(tmp_map_fd);
	if (!line)
		handle_map_error(map);
	change_last_char(line);
	map->width = ft_strlen(line);
	while (line)
	{	
		map->height++;
		free(line);
		line = get_next_line(tmp_map_fd);
		if (line)
			change_last_char(line);
	}
	close(tmp_map_fd);
}

static void count_occ(t_map *map)
{
	int	i;
	int j;
	
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				map->consum_count++;
			else if (map->map[i][j] == 'E')
				map->exit_count++;
			else if (map->map[i][j] == 'P')
				map->player_count++;
			j++;
		}
		i++;
	}
}

void map_filler(t_map *map, int map_fd)
{
	int	i;

	i = 0;
	get_map_size(map);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map)
		handle_map_error(map);
	while (i < map->height)
	{
		map->map[i] = get_next_line(map_fd);
		if (!map->map[i])
			handle_map_error(map);
		change_last_char(map->map[i]);
		i++;
	}
	map->map[i] = NULL;
	count_occ(map);
}	
