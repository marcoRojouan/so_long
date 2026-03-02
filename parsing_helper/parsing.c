/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/03/02 16:28:51 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <so_long.h>

static int	check_mapfile(char *mapfile)
{
	int	len;

	len = ft_strlen(mapfile);
	if (len < 5)
		return (0);
	if (ft_strcmp(mapfile + len - 4, "ber") != 0)
		return (0);
	return (1);
}

static void	get_map_size(t_game *game, char *mapfile)
{
	char	*line;
	int		tmp_map_fd;

	tmp_map_fd = open(mapfile, O_RDONLY);
	if (tmp_map_fd < 0)
		handle_map_error(game, "Invalid map\n");
	line = get_next_line(tmp_map_fd);
	if (!line)
	{
		close(tmp_map_fd);
		handle_map_error(game, "Invalid map\n");
	}
	change_last_char(line);
	game->width = ft_strlen(line);
	while (line)
	{
		game->height++;
		free(line);
		line = get_next_line(tmp_map_fd);
		if (line)
			change_last_char(line);
	}
	close(tmp_map_fd);
}

void	parsing(t_game *game, char *mapfile)
{
	int		map_fd;

	get_map_size(game, mapfile);
	if (check_mapfile(mapfile) != 0)
		handle_map_error(game, "Invalid file\n");
	map_fd = open(mapfile, O_RDONLY);
	if (map_fd < 0)
	{
		close(map_fd);
		handle_map_error(game, "Invalid file\n");
	}
	map_filler(game, map_fd);
	close(map_fd);
	if (!game->map || !game->map[0])
	{
		handle_map_error(game, "Invalid file\n");
	}
	verif_map(game);
	get_position(game);
	check_path(game);
}
