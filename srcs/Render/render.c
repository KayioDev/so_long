/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:38:06 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/28 20:42:21 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
			mlx_put_image_to_window(game->mlx, game->win,
				game->floor.img, x * game->floor.width, y * game->floor.height);
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall.img, x * game->wall.width, y * game->wall.height);
			else if (game->map.grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player.img, x * game->player.width, y * game->player.height);
			else if (game->map.grid[y][x] == 'E')
			{
    		if (game->collected == game->total_collectibles)
        		mlx_put_image_to_window(game->mlx, game->win,
           			game->exit_open.img, x * game->exit_open.width, y * game->exit_open.height);
    		else
        		mlx_put_image_to_window(game->mlx, game->win,
            		game->exit.img, x * game->exit.width, y * game->exit.height);
			}
			else if (game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible.img, x * game->collectible.width, y * game->collectible.height);
			x++;
		}
		y++;
	}
}
