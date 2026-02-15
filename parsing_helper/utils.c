/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:07:04 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/15 16:46:44 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include "get_next_line/get_next_line.h"

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

char	*ft_strdup(char *s)
{
	char	*duplicata;
	int		i;
	int		len;

	len = ft_strlen(s);
	duplicata = NULL;
	duplicata = malloc(sizeof(char) * len + 1);
	if (!duplicata)
		return (0);
	i = 0;
	while (i < len)
	{
		duplicata[i] = s[i];
		i++;
	}
	duplicata[i] = '\0';
	return (duplicata);
}

int ft_strnlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
