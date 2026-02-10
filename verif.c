/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:06:02 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/10 15:59:52 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static int verif_lines_len(t_map *map)
{
	int		line_size;
	int		first_line_size;
	int		i;

	first_line_size = ft_strnlen(map->map[0]);
	i = 1;
	while (i < map->height)
	{
		line_size = ft_strnlen(map->map[i]);
		if (line_size != first_line_size)
			return (0);
		i++;
	}
	return (line_size); 
}

static int verif_top_bottom(t_map *map)
{
	int i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
static int	verif_walls(t_map *map)
{
	int i;

	i = 1;
	while (i < map->height - 1)
	{
		if (map->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < map->height - 1)
	{
		if (map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void verif_map(t_map *map)
{
	if (verif_lines_len(map) == 0 || map->width <= 3)
		handle_map_error();
	if (map->height >= 0 && map->height <= 3)
		handle_map_error();
	if (verif_top_bottom(map) == 0)
		handle_map_error();
	if (verif_walls(map) == 0)
		handle_map_error();
}