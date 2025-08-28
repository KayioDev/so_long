/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:01:05 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/28 17:32:29 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	validator_map(char **grid)
{
	int	width;
	int	index;

	index = 0;
	if (!grid || !grid[0])
		return (0);
	width = ft_strlen(grid[0]);
	while (grid[index])
	{
		if ((int)ft_strlen(grid[index]) != width)
			return (0);
		index++;
	}
	return (1);
}

int	validator_rectangular(t_game *game)
{
	int	width;
	int	index;

	index = 0;
	if (!game->map.grid || !game->map.grid[0])
		return (0);
	width = ft_strlen(game->map.grid[0]);
	game->map.width = width;
	while (game->map.grid[index])
	{
		if ((int)ft_strlen(game->map.grid[index]) != width)
			return (0);
		index++;
	}
	game->map.height = index;
	if (game->map.width == game->map.height)
		return (0);
	return (1);
}
