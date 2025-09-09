/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:54 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/09 20:50:19 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	print_key_pressed(int key, t_game *game)
{
	if (!game->keys_pressed[(unsigned char)key])
	{
		game->keys_pressed[(unsigned char)key] = 1;
		game->is_moving = 1;
		game->key = key;
	}
	return (0);
}

int	release(int key, t_game *game)
{
	t_xvar	*xvar;
	XEvent	ev;

	xvar = (t_xvar *)game->mlx;
	if (XEventsQueued(xvar->display, QueuedAfterReading))
	{
		XPeekEvent(xvar->display, &ev);
		if (ev.type == KeyPress && ev.xkey.keycode == (unsigned int) key)
		{
			return (0);
		}
	}
	if (game->keys_pressed[(unsigned char)key])
	{
		game->keys_pressed[(unsigned char)key] = 0;
		if (game->key == key)
		{
			game->is_moving = 0;
			game->key = 0;
		}
	}
	return (0);
}

int	game_loop(t_game *game)
{
	static int	frame_count = 0;

	frame_count++;
	if (frame_count >= 60)
	{
		if (game->is_moving)
			keys_controls(game->key, game);
		frame_count = 0;
	}
	draw_map(game);
	return (0);
}

int	initialize_game(t_game *game)
{
	game->moves = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx,
			game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
		return (1);
	game->collected = 0;
	game->total_collectibles = count_collectibles(game);
	find_player(game);
	load_sprites(game);
	if (!validator_rectangular(game)
		|| !validator_chars(game)
		|| !validator_lines(game)
		|| !validator_lines_coluns(game))
		return (1);
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, print_key_pressed, game);
	mlx_hook(game->win, 3, 1L << 1, release, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
