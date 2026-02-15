/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:11:51 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/15 16:21:30 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void get_player_position(t_map *map, t_position *position)
{
	int	i;
	int j;
	
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j])
		{			
			if (map->map[i][j] == 'P')
			{
				position->player_y = i;
				position->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	} 
}
// static void get_player_position(t_map *map, t_position *position)
// {
// 	int	i;
// 	int j;
	
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		j = 0;
// 		while (map->map[i][j])
// 		{			
// 			if (map->map[i][j] == 'P')
// 			{
// 				position->player_y = i;
// 				position->player_x = j;
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	} 
// }
void get_position(t_map *map, t_position *position)
{
	get_player_position(&map, &position);
}