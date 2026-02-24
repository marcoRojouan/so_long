/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:13:18 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/24 14:08:16 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

void	handle_map_error(t_game *game, char *error)
{
	write(2, error, ft_strlen(error));
	if (game->map)
		free_tab(game->map);
	exit(1);
}
