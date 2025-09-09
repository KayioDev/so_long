/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:01:05 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/09 20:44:15 by klima-do         ###   ########.fr       */
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

int	validator_chars(t_game *game)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile = game->map.grid[y][x];
			if (tile != '0' && tile != '1' && tile != 'E'
				&& tile != 'C' && tile != 'P')
			{
				ft_putendl_fd("Error\nMapa contém caractere inválido.", 2);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validator_lines_coluns(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[y][x] != '1')
			return (0);
		x++;
	}
	y = game->map.height - 1;
	x = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	validator_lines(t_game *game)
{
	int	y;

	y = 1;
	while (y < game->map.height - 1)
	{
		if (game->map.grid[y][0] != '1' ||
			game->map.grid[y][game->map.width - 1] != '1')
		{
			ft_putendl_fd("Paredes invalidas\n", 2);
			return (0);
		}
		y++;
	}
	return (1);
}
