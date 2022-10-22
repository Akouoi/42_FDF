/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:28:07 by akouoi            #+#    #+#             */
/*   Updated: 2022/04/25 14:28:07 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	s_len;

	s_len = ft_strlen(s);
	d = malloc (sizeof(char) * (s_len + 1));
	if (!d)
		return (d);
	ft_strlcpy(d, s, s_len + 1);
	return (d);
}
