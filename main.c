/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:44:14 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/09 19:35:51 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	(void) argc;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening map");
		return (0);
	}
	if (!initialize_map(&game, fd))
	{
		perror("Error reading map");
		close(fd);
		return (0);
	}
	close(fd);
	initialize_game(&game);
	return (0);
}
