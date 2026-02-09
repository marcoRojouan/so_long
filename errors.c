/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:13:18 by mrojouan          #+#    #+#             */
/*   Updated: 2026/02/09 15:13:41 by mrojouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	handle_map_error(void)
{
	char	*error;

	error = "Map error";
	write(2, error, ft_strlen(error));
	exit(1);
}
