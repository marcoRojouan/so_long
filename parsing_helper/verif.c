/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:06:02 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/24 14:12:18 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

static int verif_lines_len(t_game *game)
{
	int		line_size;
	int		first_line_size;
	int		i;

	first_line_size = ft_strlen(game->map[0]);
	i = 1;
	while (i < game->height)
	{
		line_size = ft_strlen(game->map[i]);
		if (line_size != first_line_size)
			return (0);
		i++;
	}
	return (1); 
}

static int verif_top_bottom(t_game *game)
{
	int i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
static int	verif_walls(t_game *game)
{
	int i;

	i = 1;
	while (i < game->height - 1)
	{
		if (game->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < game->height - 1)
	{
		if (game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int verif_typo(t_game *game)
{
	int	i;
	int j;
	char current;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->map[i][j])
		{
			current = game->map[i][j];
			if (current != 'C' && current != 'P' && current != 'E'
					&& current != '1' && current != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1); 
}

void verif_map(t_game *game)
{
	if (verif_lines_len(game) == 0 || game->width <= 2)
		handle_map_error(game, "Map not rectangular\n");
	if (game->height <= 2)
		handle_map_error(game, "Invalid map size\n");
	if (verif_top_bottom(game) == 0)
		handle_map_error(game, "Map not close\n");
	if (verif_walls(game) == 0)
		handle_map_error(game, "Map not close\n");
	if (!(game->consum_count >= 1 
			&& game->exit_count == 1
				&& game->player_count == 1))
		handle_map_error(game, "Invalid elements\n");
	if (verif_typo(game) == 0)
		handle_map_error(game, "Invalid map\n");
}

