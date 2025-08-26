/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:44:14 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/25 17:04:18 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	(void) argc;
    t_game game;
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (1);
    if (!initialize_map(&game, fd))
        return (1);

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx,
                              game.map.width * 100,
                              game.map.height * 100,
                              "so_long test");

    draw_map(&game);
    mlx_loop(game.mlx);
}
