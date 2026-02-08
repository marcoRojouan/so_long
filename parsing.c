/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/08 16:16:20 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <so_long.h>

int verif_first_line(char *current_line)
{
	int		line_size;

	line_size = ft_strlen(current_line);
	if (line_size < 3)
		return (0);
	return (line_size);
}

int parsing(void)
{
	int		map_fd;
	char	*line;


	map_fd = open("map.ber", O_RDONLY);
	if (map_fd < 0)
	{
		perror("Map error");
		exit(1);
	}
	line = get_next_line(map_fd);
	while (line)
	{
		verif_line(line);
		line = get_next_line(map_fd);
	}

}
