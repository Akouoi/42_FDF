/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:15:23 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/16 10:49:26 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_param(t_list **lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (++i < 50)
		ft_putchar_fd('-', 1);
	i = 0;
	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			ft_printf("\n[%d]\t%s", ++i, tmp->content);
			tmp = tmp->next;
		}
	}
	return (i);
}

int	print_data(t_data *data)
{
	if (!data->win)
		return (1);
	mlx_string_put(data->mlx, data->win, \
		WIN_WID - 200, WIN_HEI - 170, RED, "[R] [G] [B]   COLORS");
	mlx_string_put(data->mlx, data->win, \
		WIN_WID - 200, WIN_HEI - 140, WHITE, "[-] [=/+]     ZOOM");
	mlx_string_put(data->mlx, data->win, \
		WIN_WID - 200, WIN_HEI - 120, WHITE, "[scroll]");
	return (0);
}

	// printf("MIN X %.0f\n", data->arg->min_x);
	// printf("MAX X %.0f\n", data->arg->max_x);
	// printf("MIN Y %.0f\n", data->arg->min_y);
	// printf("MAX Y %.0f\n\n", data->arg->max_y);