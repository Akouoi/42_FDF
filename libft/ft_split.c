/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:27:24 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/03 10:42:10 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_clear(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	ft_w_nbr(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			count++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static size_t	ft_w_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static size_t	ft_filltab(char *dest, char *src, char c, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_w_len(src, c));
	while (src[i] && src[i] != c && src[i] != ',' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_w_len(src, c));
}

char	**ft_split(char *s, char c)
{
	char	**p;
	size_t	w_nbr;
	size_t	i;

	i = 0;
	w_nbr = ft_w_nbr(s, c);
	p = malloc(sizeof(char *) * (w_nbr + 1));
	if (!p)
		return (NULL);
	while (*s && i < w_nbr)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			p[i] = malloc ((ft_w_len(&(*s), c) + 1) * sizeof(char));
			if (!p[i])
				return (ft_clear(p));
			ft_filltab(p[i++], &(*s), c, ft_w_len(&(*s), c) + 1);
		}
		while (*s && *s != c)
			s++;
	}
	p[i] = NULL;
	return (p);
}
