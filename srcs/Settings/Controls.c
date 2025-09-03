/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:58:53 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/03 13:58:47 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_player(t_game *game, int dy, int dx)
{
	int	new_y;
	int	new_x;

	new_x = game->player_game.x + dx;
	new_y = game->player_game.y + dy;
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (game->map.grid[new_y][new_x] == 'E' &&
		game->collected != game->total_collectibles)
		return ;
	type_move(game, new_y, new_x);
	game->moves++;
	printf("Moves: %d\n", game->moves);
	game->map.grid[game->player_game.y][game->player_game.x] = '0';
	game->player_game.y = new_y;
	game->player_game.x = new_x;
	game->map.grid[new_y][new_x] = 'P';
	draw_map(game);
}

void	type_move(t_game *game, int new_y, int new_x)
{
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map.grid[new_y][new_x] = '0';
	}
	if (game->map.grid[new_y][new_x] == 'E' &&
		game->collected == game->total_collectibles)
	{
		printf("Você venceu!\n");
		exit_game(game);
	}
}

int	keys_controls(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119)
		move_player(game, -1, 0);
	else if (keycode == 115)
		move_player(game, 1, 0);
	else if (keycode == 97)
		move_player(game, 0, -1);
	else if (keycode == 100)
		move_player(game, 0, 1);
	return (0);
}
