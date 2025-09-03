/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:13:53 by klima-do          #+#    #+#             */
/*   Updated: 2025/09/02 17:13:37 by klima-do         ###   ########.fr       */
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
		array[i] = ft_strdup(lines->content);
		if (!array[i])
		{
			while (i > 0)
				free(array[--i]);
			free(array);
			return (NULL);
		}
		i++;
		lines = lines->next;
	}
	array[i] = NULL;
	return (array);
}

t_list	*create_list(int fd, int *width)
{
	t_list	*lst_lines;
	char	*line;
	size_t	len;

	lst_lines = NULL;
	*width = -1;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (*width == -1)
			*width = ft_strlen(line);
		else if ((int)ft_strlen(line) != *width)
		{
			free(line);
			ft_lstclear(&lst_lines, free);
			return (NULL);
		}
		ft_lstadd_back(&lst_lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (lst_lines);
}

int	initialize_map(t_game *game, int fd)
{
	t_list	*lst_lines;
	int		width;

	lst_lines = create_list(fd, &width);
	if (!lst_lines)
		return (0);
	game->map.height = ft_lstsize(lst_lines);
	game->map.width = width;
	game->map.grid = list_to_array(lst_lines);
	ft_lstclear(&lst_lines, free);
	return (1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
