/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:43:56 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/09 13:24:22 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <so_long.h>

static int ft_strnlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static void	handle_map_error(void)
{
	char	*error;

	error = "Map error";
	write(2, error, ft_strlen(error));
	exit(1);
}

static int verif_first_line(char *current_line)
{
	int		line_size;

	line_size = ft_strnlen(current_line);
	if (line_size <= 3)
		return (0);
	return (line_size);
}

static int verif_line(char *current_line, int first_line_size)
{
	int		line_size;

	line_size = ft_strnlen(current_line);
	if (line_size != first_line_size)
		return (0);
	return (1);
}

int parsing(void)
{
	int		map_fd;
	int		fisrt_size;
	int		line_counter; 
	char	*line;

	map_fd = open("map.ber", O_RDONLY);
	if (map_fd < 0)
	{
		perror("Map error");
		exit(1);
	}
	line = get_next_line(map_fd);
	if (!line)
	{
		printf("is no good");
		exit(1);
	}
	fisrt_size = verif_first_line(line);
	if (fisrt_size == 0)
	{
		printf("is no good");
		exit(1);
	}
	line_counter = 1;
	while (line)
	{
		if (verif_line(line, fisrt_size) == 0)
		{
			printf("is no good");
			exit(1);
		}
		line = get_next_line(map_fd);
		line_counter++;
	}
	if (line_counter <= 3)
	{
		printf("is no good");
		exit(1);
	}
	return (1);
}
