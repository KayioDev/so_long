/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:34:03 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/09 20:36:01 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "assert.h"
# include <unistd.h>
# include "Libft/libft.h"
# define TILE_SIZE 32
# include <stdio.h>
# include "minilibx-linux/mlx_int.h"
# include "Libft/Ft_Printf/ft_printf.h"

typedef struct s_player {
	int		x;
	int		y;
	void	*img;
	int		width;
	int		height;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		player_x;
	int		player_y;
	int		exit_count;
}	t_map;
typedef struct s_imge
{
	void	*img;
	int		width;
	int		height;
	int		value;
}	t_imge;

typedef struct s_game {
	void			*mlx;
	void			*win;
	int				collected;
	int				total_collectibles;
	int				moves;
	t_map			map;
	t_imge			wall;
	t_imge			floor;
	t_imge			player;
	t_imge			exit;
	t_imge			exit_open;
	t_imge			collectible;
	t_player		player_game;
	int				is_moving;
	int				key;
	int				frames;
	int				movement_accum;
	unsigned int	keys_pressed[256];
}	t_game;

void	load_sprites(t_game *game);
int		initialize_game(t_game *game);
int		initialize_map(t_game *game, int fd);
int		keys_controls(int keycode, t_game *game);
void	find_player(t_game *game);
void	print_map(char **map);
void	draw_map(t_game *game);
void	exit_game(t_game *game);
void	find_player(t_game *game);
int		keys_controls(int keycode, t_game *game);
int		count_collectibles(t_game *game);
int		keys_controls(int keycode, t_game *game);
void	move_player(t_game *game, int dy, int dx);
int		validator_rectangular(t_game *game);
void	printf_moves(t_game *game);
void	type_move(t_game *game, int new_y, int new_x);
void	put_img(t_game *game, t_imge img, int x, int y);
int		validator_chars(t_game *game);
int		validator_lines(t_game *game);
int		validator_lines_coluns(t_game *game);

#endif
