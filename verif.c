/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:06:02 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/09 16:30:21 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

int verif_lines_len(t_map *map)
{
	int		line_size;
	int		first_line_size;
	int		i;

	first_line_size = ft_strnlen(map->map[0]);
	i = 1;
	while (i < map->map_size)
	{
		line_size = ft_strnlen(map->map[1]);
		if (line_size != first_line_size)
			return (0);
	}
	return (1); 
}

void verif_map(t_map *map)
{
	if (verif_lines_len(map) == 0)
		handle_map_error;
	
	
}