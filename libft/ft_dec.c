/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:09 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/23 13:05:20 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoa(int n, char *base)
{
	char	*str;
	int		sign;
	int		n_len;
	int		base_len;

	base_len = pf_strlen(base);
	sign = 1 - 2 * (n < 0);
	n *= sign;
	n_len = pf_nblen(n, base_len);
	str = malloc((n_len + 1 + (sign < 0)) * sizeof(char));
	if (!str)
		return (NULL);
	str[n_len + (sign < 0)] = 0;
	while (--n_len + (sign < 0) >= 0)
	{
		str[n_len + (sign < 0)] = base[n % base_len];
		n /= base_len;
	}
	if (sign < 0)
		str[0] = '-';
	write(1, str, pf_strlen(str));
	return (str);
}

int	pf_putnbr_dec(va_list ap, int i)
{
	char	*str;
	int		n_len;
	int		n;

	n_len = 0;
	n = va_arg(ap, int);
	if (n >= 0)
	{
		if (i == 8)
			n_len += write(1, " ", 1);
		if (i == 9)
			n_len += write(1, "+", 1);
	}
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	str = pf_itoa(n, "0123456789");
	n_len += pf_strlen(str);
	free(str);
	return (n_len);
}

int	pf_utoa(va_list ap, int i)
{
	unsigned int	n;
	char			*str;
	int				n_len;

	if (i == 5)
		n = va_arg(ap, unsigned int);
	n_len = pf_nblen(n, 10);
	str = malloc((n_len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[n_len] = 0;
	while (--n_len >= 0)
	{
		str[n_len] = n % 10 + '0';
		n /= 10;
	}
	write(1, str, pf_strlen(str));
	n_len = pf_strlen(str);
	free(str);
	return (n_len);
}
