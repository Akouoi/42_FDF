/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_define_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:41:32 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/16 11:57:00 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize(t_data *data)
{
	float	scale;
	int		x;
	int		y;

	if ((data->arg->max_x - data->arg->min_x) / WIN_WID \
		> (data->arg->max_y - data->arg->min_y) / WIN_HEI)
		scale = WIN_WID / (data->arg->max_x - data->arg->min_x);
	else
		scale = WIN_HEI / (data->arg->max_y - data->arg->min_y);
	y = 0;
	while (y < data->ly)
	{
		x = 0;
		while (x < data->lx)
		{
			data->pix[y][x].x = (data->pix[y][x].x) * scale;
			data->pix[y][x].y = (data->pix[y][x].y) * scale;
			x++;
		}
		y++;
	}
}

void	center(t_data *data)
{
	int	x;
	int	y;

	find_min(data);
	y = 0;
	while (y < data->ly)
	{
		x = 0;
		while (x < data->lx)
		{
			data->pix[y][x].x = (data->pix[y][x].x - data->arg->min_x \
				+ (WIN_WID - (data->arg->max_x - data->arg->min_x)) / 2);
			data->pix[y][x].y = (data->pix[y][x].y - data->arg->min_y \
				+ (WIN_HEI - (data->arg->max_y - data->arg->min_y)) / 2);
			x++;
		}
		y++;
	}
}

void	define_window(t_data *data)
{
	find_min(data);
	ft_printf("x_scope %d\ty_scope %d\nWID %d\tHEI %d\n", \
		(int)(data->arg->max_x - data->arg->min_x), \
		(int)(data->arg->max_y - data->arg->min_y), IMG_WID, IMG_HEI);
	if (data->lx < IMG_WID \
		&& data->ly < IMG_HEI)
	{
		ft_printf("\t\t\t%s=======IMG_SIZE OK=======%s\n", GREEN_B, COL);
		resize(data);
		center(data);
	}
	else
	{
		ft_printf("\t\t\t%s===Redefine IMG_WID/HEI===%s\n", RED_B, COL);
		exit(0);
	}
}
