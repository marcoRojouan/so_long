/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 16:38:46 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/22 17:27:41 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

int exit_window(t_game *game)
{
	if (game->map)
		free_tab(game->map);
	if (game->mlx)
	{
		if (game->floor)
			mlx_destroy_image(game->mlx, game->floor);
		if (game->wall)
			mlx_destroy_image(game->mlx, game->wall);
		if (game->player)
			mlx_destroy_image(game->mlx, game->player);
		if (game->collect)
			mlx_destroy_image(game->mlx, game->collect);
		if (game->exit)
			mlx_destroy_image(game->mlx, game->exit);
		if (game->window)
			mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}