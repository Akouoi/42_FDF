/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:27:47 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/18 13:51:03 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	c = c % 256;
	p = (char *)s;
	if (c == '\0')
		return (p);
	while (*p)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (NULL);
}
