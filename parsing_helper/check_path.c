/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:35:15 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/27 11:17:15 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static char	**copy_map(t_game *game)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (game->height + 1));
	if (!copy)
		return (NULL);
	while (i < game->height)
	{
		copy[i] = ft_strdup(game->map[i]);
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

static int	is_filled(char **map)
{
	int		i;
	int		j;
	char	current;

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

void	check_path(t_game *game)
{
	char	**map_copy;

	map_copy = copy_map(game);
	if (!map_copy)
		handle_map_error(game, "Invalid map\n");
	flood_fill(map_copy, game, game->player_y, game->player_x);
	if (!is_filled(map_copy))
	{
		free_tab(map_copy);
		handle_map_error(game, "Invalid game path\n");
	}
	free_tab(map_copy);
}
