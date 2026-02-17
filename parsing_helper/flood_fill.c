/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:32:18 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/17 12:00:52 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	fill(char **tab, t_map *size, char wall, int row, int col)
{
	if (row < 0 || col < 0 || row >= size->height || col >= size->width)
		return ;
	if (tab[row][col] == wall || tab[row][col] == 'F')
		return ;
	if (tab[row][col] == 'E')
	{
		tab[row][col] = 'F';
		return ;
	}
	tab[row][col] = 'F';
	fill(tab, size, wall, row - 1, col);
	fill(tab, size, wall, row + 1, col);
	fill(tab, size, wall, row, col - 1);
	fill(tab, size, wall, row, col + 1);
	
}

void	flood_fill(char **copy, t_map *map, int player_y, int player_x)
{
	char wall;

	wall = '1';
	fill(copy, map, wall, player_y, player_x);
}