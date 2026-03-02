/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:11:21 by mrojouan          #+#    #+#             */
/*   Updated: 2026/03/02 15:18:18 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

void	change_last_char(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static void	count_occ(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->consum_count++;
			else if (game->map[i][j] == 'E')
				game->exit_count++;
			else if (game->map[i][j] == 'P')
				game->player_count++;
			j++;
		}
		i++;
	}
}

void	map_filler(t_game *game, int map_fd)
{
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
	{
		close(map_fd);
		handle_map_error(game, "Invalid map\n");
	}
	while (i < game->height)
	{
		game->map[i] = get_next_line(map_fd);
		if (!game->map[i])
		{
			close(map_fd);
			handle_map_error(game, "Invalid map\n");
		}
		change_last_char(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
	count_occ(game);
}
