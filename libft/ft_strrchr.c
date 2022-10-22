/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:31:04 by akouoi            #+#    #+#             */
/*   Updated: 2022/07/10 18:04:28 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 256)
		c %= 256;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(int argc, char *av[])
{
	if (argc == 3)
	{
		char * result_ptr = ft_strrchr(av[1], av[2][0]);
		if (result_ptr)
			printf("%s\n", result_ptr);
		else
			puts("RESULT IS NULL");
	}
}*/
