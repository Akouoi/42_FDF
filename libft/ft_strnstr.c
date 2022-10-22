/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:30:30 by akouoi            #+#    #+#             */
/*   Updated: 2022/04/25 15:30:30 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i] && len > 0)
	{
		j = 0;
		while (big[i + j] == little[j] && len - j > 0)
		{
			if (little[j + 1] == '\0')
				return (&((char *)big)[i]);
			j++;
		}
		i++;
		len--;
	}
	return (NULL);
}
/*
int	main()
{
	printf("%s\n", ft_strnstr("aaabcabcd", "cd", 8));
}*/