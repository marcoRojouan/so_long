/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:07:04 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/12 14:25:43 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void free_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int ft_strnlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
