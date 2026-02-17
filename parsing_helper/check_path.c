/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:35:15 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/17 11:42:37 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static char **copy_map(t_map *map)
{
	char **copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int is_filled(char **map)
{
	int	i;
	int j;
	char current;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			current = map[i][j];
			if (current == 'C' || current == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1); 
}

void check_path(t_map *map, t_position *position)
{
	char **map_copy;

	map_copy = copy_map(map);
	if (!map_copy)
		handle_map_error(map);
	flood_fill(map_copy, map, position->player_y, position->player_x);
	if (!is_filled(map_copy))
	{
		free_tab(map_copy);
		handle_map_error(map);
	}
	free_tab(map_copy);
}