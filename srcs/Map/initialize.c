/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:33:54 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/25 17:07:48 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// int	initialize(t_game *game, char *map_file)
// {
// 	game->mlx = mlx_init();
// 	if (!game->mlx)
// 		return (0);
// 	if (!load_map(game, map_file))
// 		return (0);
//     game->win = mlx_new_window(game->mlx,
//                                game->map.width * TILE_SIZE,
//                                game->map.height * TILE_SIZE,
//                                "so_long");
// 	if (!game->win)
// 		return (0);
// 	if (!load_textures(game))
// 		return (0);
//     // mlx_key_hook(game->win, handle_key, game);
//     // mlx_hook(game->win, 17, 0, handle_exit, game);
//     return (1);
// }