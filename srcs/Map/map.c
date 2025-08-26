/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:13:53 by klima-do          #+#    #+#             */
/*   Updated: 2025/08/25 17:32:05 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**list_to_array(t_list *lines)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc(sizeof(char *) * (ft_lstsize(lines) + 1));
	if (!array)
		return (NULL);
	while (lines)
	{
		array[i++] = lines->content;
		lines = lines->next;
	}
	array[i] = NULL;
	return (array);

}

int	initialize_map(t_game *game, int fd)
{
	char	*line;
	t_list	*lines = NULL;
	int		width = -1;

	while ((line = get_next_line(fd)))
	{
		if (line[ft_strlen(line)] -1 == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (width == -1)
			width = ft_strlen(line);
		else if (ft_strlen(line) != (int)width)
			return (0);
		ft_lstadd_back(&lines, ft_lstnew(line));
	}
	if (!lines)
		return (0);
	game->map.height = ft_lstsize(lines);
	game->map.width = width;
	game->map.grid = list_to_array(lines);
	return (1);
}

void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}
