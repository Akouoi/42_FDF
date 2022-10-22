/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:20 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/24 09:40:01 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(va_list ap, int i)
{
	char	*str;

	i = 0;
	str = va_arg(ap, void *);
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		i += write (1, &str[i], 1);
	return (i);
}

int	pf_putchar(va_list ap, int i)
{
	int	c;

	if (!i)
		c = va_arg(ap, int);
	return (write(1, &c, 1));
}

size_t	pf_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	pf_nblen(unsigned long long int n, unsigned long long int base_len)
{
	int	power;

	power = 0;
	while (n >= base_len)
	{
		power++;
		n /= base_len;
	}
	return (power + 1);
}
