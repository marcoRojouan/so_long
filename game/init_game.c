/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:53:29 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/17 16:05:52 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

void init_game(void *mlx)
{
	t_tiles *tiles;

	tiles->floor = mlx_xpm_file_to_image(
		mlx, "../texture/sol.xmp", tiles->tile_width, tiles->tile_height);
}