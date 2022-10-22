/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:52:24 by akouoi            #+#    #+#             */
/*   Updated: 2022/05/23 13:12:52 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>

int		pf_putstr(va_list ap, int i);
int		pf_putchar(va_list ap, int i);
size_t	pf_strlen(const char *str);
int		pf_nblen(unsigned long long int n, unsigned long long int base_len);
char	*pf_itoa(int n, char *base);
int		pf_putnbr_dec(va_list ap, int i);
char	*pf_itoa_base(unsigned long long int n, char *base);
int		pf_putnbr_hex(va_list ap, int i);
int		pf_putnbr_hexm(va_list ap, int i);
int		ft_printf(const char *s, ...);
int		ft_format(va_list ap, int i);
int		pf_point(va_list ap, int i);
int		id(char c);
int		pf_utoa(va_list ap, int i);

#endif
