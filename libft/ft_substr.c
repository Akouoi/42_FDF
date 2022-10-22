/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:32:14 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/04 20:55:11 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (ft_strlen(s) < start)
	{
		sub = ft_calloc(1, sizeof(char));
		return (sub);
	}
	else if (ft_strlen(s) < len)
		sub = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	else
		sub = ft_calloc((len - start * (start + len > ft_strlen(s)) + 1), 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
int	main()
{
	char * s;
	
	s = ft_substr("tripouille", 100, 1);
	printf("ft_substr(\"tripouille\", 100, 1) %s\n", s);
	s = ft_substr("tripouille", 1, 1);
	printf("ft_substr(\"tripouille\", 1, 1) %s\n", s);

}*/