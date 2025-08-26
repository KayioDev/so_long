/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:03 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/25 18:41:11 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <unistd.h>
# include "Libft/libft.h"
# define TILE_SIZE 64
# include <stdio.h>
typedef struct s_map
{
	char    **grid;      // o mapa em si
	int     width;       // largura (colunas)
	int     height;      // altura (linhas)
	int     collectibles;
	int     player_x;
	int     player_y;
	int     exit_count;
}   t_map;

typedef struct s_game {
    void *mlx;
    void *win;
    t_map map;

    void *wall;
    void *floor;
    void *player;
    void *exit;
    void *collectible;
}   t_game;


int initialize(t_game *game, char *map_file);
int	initialize_map(t_game *game, int fd);
void print_map(char **map);
void draw_map(t_game *game);

#endif
