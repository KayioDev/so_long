/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:46:49 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/28 20:03:03 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	load_sprites(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"Assets/wall.xpm", &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"Assets/floor.xpm", &game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"Assets/player_0.xpm", &game->player.width, &game->player.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"Assets/exit_closed.xpm", &game->exit.width, &game->exit.height);
	game->exit_open.img = mlx_xpm_file_to_image(game->mlx,
			"Assets/exit_open.xpm", &game->exit_open.width, & game->exit_open.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"Assets/collectible.xpm",&game->collectible.width, &game->collectible.height);
}
