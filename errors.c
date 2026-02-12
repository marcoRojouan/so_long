/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:13:18 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/12 14:24:57 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

void	handle_map_error(t_map *map)
{
	char	*error;

	error = "Map error";
	write(2, error, ft_strlen(error));
	if (map->map)
		free_tab(map->map);
	exit(1);
}
