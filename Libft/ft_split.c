/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:08:27 by klima-do          #+#    #+#             */
/*   Updated: 2025/07/28 15:07:34 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_word(const char *str, char sep);

static int	split_fill(char **arr, const char *s, const char c, size_t i);

static char	**ft_free_split(char **arr_ptr);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	w_count;
	size_t	w_len;
	char	**result_array;

	if (!s)
		return (NULL);
	w_count = count_word(s, c);
	i = 0;
	result_array = malloc(sizeof(char *) * (w_count + 1));
	if (!result_array)
		return (NULL);
	while (i < w_count)
	{
	w_len = split_fill(result_array, s, c, i);
		if (!result_array)
			return (ft_free_split(result_array));
		while (*s && *s == c)
			s++;
	s = s + w_len;
	i++;
	}
	result_array[i] = (NULL);
	return (result_array);
}

static int	count_word(const char *str, char sep)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			count++;
			while (*str && *str != sep)
				str++;
		}
	}
	return (count);
}

static int	split_fill(char **arr, const char *s, const char c, size_t i)
{
	size_t	w_len;

	while (*s && *s == c)
		s++;
	w_len = 0;
	while (s[w_len] && s[w_len] != c)
		w_len++;
	arr[i] = ft_substr(s, 0, w_len);
	if (!arr[i])
		return (0);
	return (w_len);
}

static char	**ft_free_split(char **arr_ptr)
{
	int	index;

	index = 0;
	if (!arr_ptr)
		return (NULL);
	while (arr_ptr[index])
	{
		free(arr_ptr[index]);
		index++;
	}
	free(arr_ptr);
	return (NULL);
}
