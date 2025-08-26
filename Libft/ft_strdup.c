/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klima-do <klima-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:10:18 by klima-do          #+#    #+#             */
/*   Updated: 2025/07/16 16:31:15 by klima-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*start;
	size_t	size;

	size = ft_strlen(s);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	start = str;
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (start);
}
