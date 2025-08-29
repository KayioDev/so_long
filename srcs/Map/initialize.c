/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:54 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/28 20:49:04 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	initialize_game(t_game *game)
{
	game->moves = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		return (1);
	game->collected = 0;
	game->total_collectibles = count_collectibles(game);
	find_player(game);
	load_sprites(game);
	if (!validator_rectangular(game))
	{
		write(2, "Error: map is not rectangular\n", 30);
		return (1);
	}
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, keys_controls, game);
	mlx_loop(game->mlx);
	return (0);
}

