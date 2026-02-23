/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:53:29 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/23 15:29:58 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

static int init_texture(t_game *game)
{
	game->tile_width = 32;
	game->tile_height = 32;
	game->floor = mlx_xpm_file_to_image(
		game->mlx, "texture/floor.xpm", &game->tile_width, &game->tile_height);
	game->collect = mlx_xpm_file_to_image(
		game->mlx, "texture/file.xpm", &game->tile_width, &game->tile_height);
	game->exit = mlx_xpm_file_to_image(
		game->mlx, "texture/exit.xpm", &game->tile_width, &game->tile_height);
	game->player = mlx_xpm_file_to_image(
		game->mlx, "texture/ordinateur.xpm", &game->tile_width, &game->tile_height);
	game->wall = mlx_xpm_file_to_image(
		game->mlx, "texture/wall.xpm", &game->tile_width, &game->tile_height);
	if (!game->floor || !game->wall	|| !game->player || !game->collect
		|| !game->exit)
		return (0);
	return (1);
}

static void display_tile(t_game *game, char current , int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->window, game->floor, j * 32, i * 32);
	if (current == '1')
		mlx_put_image_to_window(
			game->mlx, game->window, game->wall, j * 32, i * 32);
	else if (current == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->player, j * 32, i * 32);
	else if (current == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collect, j * 32, i * 32);
	else if (current == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit, j * 32, i * 32);
}

void send_current_tile(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			display_tile(game, game->map[i][j], i, j);
			j++;
		}
		i++;
	}
} 

void init_game(t_game *game)
{
	game->window = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "PROUT");
	if (!game->window)
		handle_map_error(game);
	if (!init_texture(game))
		handle_map_error(game);
	send_current_tile(game);
	mlx_hook(game->window, 2, 1L<<0, key_press, game);
	mlx_hook(game->window, 17, 0, exit_window, game);
}