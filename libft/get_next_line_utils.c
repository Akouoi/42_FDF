/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:25:50 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/18 13:52:09 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_n_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	i += (str[i] == '\n');
	return (i);
}

// char	*ft_strchr(char *s, int c)
// {
// 	char	*p;

// 	p = (char *)s;
// 	if (c == '\0')
// 		return (p);
// 	while (*p)
// 	{
// 		if (*p == c)
// 			return (p);
// 		p++;
// 	}
// 	return (NULL);
// }

// void	ft_strlcpy(char *dest, char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size == 0)
// 		return ;
// 	while (src[i] && i < size)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// }
