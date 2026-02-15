/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:35:15 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/15 17:07:37 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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


void check_path(t_map *map, t_position *position)
{
	char **map_copy;

	map_copy = copy_map(map);
	flood_fill(map_copy, map, position->player_y, position->player_x);
	free_tab(map_copy);
}