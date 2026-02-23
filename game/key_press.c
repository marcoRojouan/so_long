/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:56:45 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/23 15:52:23 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

static void refacto_map(t_game *game, int new_posx, int new_posy)
{
	
}

static void rerender(t_game *game, int x, int y)
{
	int new_posx;
	int new_posy;

	new_posx = game->player_x + x;
	new_posy = game->player_y + y;

	if (game->map[new_posy][new_posx] == 'C')
		game->consum_count--;
	if (game->map[new_posy][new_posx] == 'E' 
			|| game->map[new_posy][new_posx] == '1')
	{
		if (game->map[new_posy][new_posx] == 'E' 
			&& game->consum_count == 0)
		{
			exit_window(game);
		}
		return ;
	}
	refacto_map(game, new_posx, new_posy);
	mlx_clear_window(game->mlx, game->window);
	send_current_tile(game);
}


int key_press(int keypress, t_game *game)
{
	if (keypress == XK_Escape)
		exit_window(game);
	if (keypress == XK_w)
		rerender(game, 0, -1);
	if (keypress == XK_d)
		rerender(game, 1, 0);
	if (keypress == XK_a)
		rerender(game, -1, 0);
	if (keypress == XK_s)
		rerender(game, 0, 1);
	return (0);
}