/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:53:29 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/19 14:24:25 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

static void init_texture(t_tiles *tiles, void *mlx)
{
	tiles->tile_width = 32;
	tiles->tile_height = 32;
	tiles->floor = mlx_xpm_file_to_image(
		mlx, "texture/floor.xpm", &tiles->tile_width, &tiles->tile_height);
	tiles->collect = mlx_xpm_file_to_image(
		mlx, "texture/file.xpm", &tiles->tile_width, &tiles->tile_height);
	tiles->exit = mlx_xpm_file_to_image(
		mlx, "texture/exit.xpm", &tiles->tile_width, &tiles->tile_height);
	tiles->player = mlx_xpm_file_to_image(
		mlx, "texture/ordinateur.xpm", &tiles->tile_width, &tiles->tile_height);
	tiles->wall = mlx_xpm_file_to_image(
		mlx, "texture/wall.xpm", &tiles->tile_width, &tiles->tile_height);
}

static void display_tile(
	t_tiles *tiles, void *mlx, void *window, char current , int i, int j)
{
	mlx_put_image_to_window(mlx, window, tiles->floor, j * 32, i * 32);
	if (current == '1')
		mlx_put_image_to_window(
			mlx, window, tiles->wall, j * 32, i * 32);
	else if (current == 'P')
		mlx_put_image_to_window(mlx, window, tiles->player, j * 32, i * 32);
	else if (current == 'C')
		mlx_put_image_to_window(mlx, window, tiles->collect, j * 32, i * 32);
	else if (current == 'E')
		mlx_put_image_to_window(mlx, window, tiles->exit, j * 32, i * 32);
}

static void send_current_tile(t_tiles *tiles, void *mlx, void *window, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			display_tile(tiles, mlx ,window, map->map[i][j], i, j);
			j++;
		}
		i++;
	}
} 

void init_game(void *mlx, t_map *map)
{
	t_tiles tiles;
	void *window;

	window = mlx_new_window(mlx, map->width * 32, map->height * 32, "PROUT");
	init_texture(&tiles, mlx);
	send_current_tile(&tiles, mlx, window, map);
	mlx_loop(mlx);
}