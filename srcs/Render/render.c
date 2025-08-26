/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:38:06 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/25 18:18:05 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void draw_map(t_game *game)
{
	int y;
	int x;
	char s[2];

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			s[0] = game->map.grid[y][x];
			s[1] = '\0';
			mlx_string_put(game->mlx, game->win,
						   x * 100, y * 100, 0xFFFFFF, s);
			x++;
		}
		y++;
	}
}
