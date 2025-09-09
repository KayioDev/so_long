/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:38:06 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/09 20:49:24 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_img(t_game *game, t_imge img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		img.img, x * img.width, y * img.height);
}

static void	draw_exit(t_game *game, int x, int y)
{
	if (game->collected == game->total_collectibles)
		put_img(game, game->exit_open, x, y);
	else
		put_img(game, game->exit, x, y);
}

static void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map.grid[y][x];
	if (tile == '1')
		put_img(game, game->wall, x, y);
	else if (tile == 'P')
		put_img(game, game->player, x, y);
	else if (tile == 'E')
		draw_exit(game, x, y);
	else if (tile == 'C')
		put_img(game, game->collectible, x, y);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_img(game, game->floor, x, y);
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
