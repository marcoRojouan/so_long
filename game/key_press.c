/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:56:45 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/24 14:07:36 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>

void	ft_putnbr_fd(int nbr, int fd)
{
	char	c;

	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}

static void print_moves(t_game *game)
{
	write(1, "Deplacement = ", 14);
	ft_putnbr_fd(game->move_count, 1);
	write(1, "\n", 1);
}

static void refacto_map(t_game *game, int new_posx, int new_posy)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_posy][new_posx] = 'P';
	game->player_x = new_posx;
	game->player_y = new_posy;
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
	game->move_count++;
	refacto_map(game, new_posx, new_posy);
	print_moves(game);
	mlx_clear_window(game->mlx, game->window);
	send_current_tile(game);
}

int key_press(int keypress, t_game *game)
{
	if (keypress == XK_Escape)
		exit_window(game);
	if (keypress == XK_Up)
		rerender(game, 0, -1);
	if (keypress == XK_Right)
		rerender(game, 1, 0);
	if (keypress == XK_Left)
		rerender(game, -1, 0);
	if (keypress == XK_Down)
		rerender(game, 0, 1);
	return (0);
}