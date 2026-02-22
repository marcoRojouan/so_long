/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/22 16:54:20 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <so_long.h>

void parsing(t_game *game)
{
	int		map_fd;
	
	map_fd = open("map.ber", O_RDONLY);
	if (map_fd < 0)
	{
		close(map_fd);
		handle_map_error(game);
	}
	map_filler(game, map_fd);
	if (!game->map || !game->map[0])
	{
		close(map_fd);
		handle_map_error(game);
	}
	verif_map(game);
	get_position(game);
	check_path(game);
	close(map_fd);
}
