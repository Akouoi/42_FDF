/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:13:25 by akouoi            #+#    #+#             */
/*   Updated: 2022/04/25 14:13:25 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while (n--)
	{
		if (*s_1 != *s_2)
			return (*s_1 - *s_2);
		s_1++;
		s_2++;
	}
	return (0);
}
/*
int	main()
{
    size_t    n = 7;
    char    s1[10] = "halting";
    char    s2[10] = "halting";

    if (ft_memcmp(s1, s2, n) != memcmp(s1, s2, n))
    {
        printf("KO\n");
        return (0);
    }
    printf("OK\n");
    return (1);
}*/