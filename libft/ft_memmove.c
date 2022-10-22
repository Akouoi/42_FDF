/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:11:07 by akouoi            #+#    #+#             */
/*   Updated: 2022/04/30 13:11:07 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dest < src)
	{
		d = (char *)dest;
		s = (const char *)src;
		while (n--)
		*d++ = *s++;
	}
	else
	{
		d = (char *)dest + (n - 1);
		s = (const char *)src + (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
