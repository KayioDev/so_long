/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:03 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/27 20:19:57 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "assert.h"
# include <unistd.h>
# include "Libft/libft.h"
# define TILE_SIZE 64
# include <stdio.h>

typedef struct s_player {
    int x;
    int y;
    void *img;
    int width;
    int height;
}   t_player;

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
typedef struct s_img
{
    void *img;
    int   width;
    int   height;
}   t_img;

typedef struct s_game {
    void *mlx;
    void *win;
	int collected;
    int total_collectibles;
    t_map map;
    t_img wall;
    t_img floor;
    t_img player;
    t_img exit;
    t_img collectible;
	t_player player_game;
}   t_game;


void load_sprites(t_game *game);
int initialize_game(t_game *game);
int	initialize_map(t_game *game, int fd);
int exit_program(int keycode, t_game *game);

void print_map(char **map);
void draw_map(t_game *game);
#endif
