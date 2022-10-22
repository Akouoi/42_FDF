/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:21:19 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/15 21:12:31 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_close(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		mlx_loop_end(data);
	return (0);
}

int	shift_pix(t_data *data, int shift_x, int shift_y)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->ly)
	{
		x = 0;
		while (x < data->lx)
		{
			data->pix[y][x].x += shift_x;
			data->pix[y][x].y += shift_y;
			x++;
		}
		y++;
	}
	return (0);
}

int	zoom(t_data *data, float zoom)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->ly)
	{
		x = 0;
		while (x < data->lx)
		{
			data->pix[y][x].x = data->pix[y][x].x * zoom;
			data->pix[y][x].y = data->pix[y][x].y * zoom;
			x++;
		}
		y++;
	}
	find_min(data);
	center(data);
	find_min(data);
	return (0);
}

int	mouse_hooks(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	find_min(data);
	if (keycode == 5)
		if ((data->arg->max_y - data->arg->min_y) * 0.95 > (WIN_HEI * 0.6))
			return (zoom(data, 0.95));
	if (keycode == 4)
		if ((data->arg->max_y - data->arg->min_y) * 1.05 < IMG_HEI)
			return (zoom(data, 1.05));
	return (0);
}

int	key_hooks(int keycode, t_data *data)
{
	find_min(data);
	if (keycode == left)
		return (shift_pix(data, (data->arg->min_x - data->arg->max_x) / S, 0));
	if (keycode == right)
		return (shift_pix(data, (data->arg->max_x - data->arg->min_x) / S, 0));
	if (keycode == up)
		return (shift_pix(data, 0, (data->arg->min_x - data->arg->max_x) / S));
	if (keycode == down)
		return (shift_pix(data, 0, (data->arg->max_y - data->arg->min_y) / S));
	if (keycode == '-' || keycode == 65453)
		if ((data->arg->max_y - data->arg->min_y) * 0.95 > (WIN_HEI * 0.6))
			return (zoom(data, 0.95));
	if (keycode == '=' || keycode == 65451)
		if ((data->arg->max_y - data->arg->min_y) * 1.05 < IMG_HEI)
			return (zoom(data, 1.05));
	if (keycode == 'g')
		return (data->bg_col = GREEN, ft_printf("Keycode = %c\n", keycode - 32));
	if (keycode == 'r')
		return (data->bg_col = D_RED, ft_printf("Keycode = %c\n", keycode - 32));
	if (keycode == 'b')
		return (data->bg_col = BLACK, ft_printf("Keycode = %c\n", keycode - 32));
	return (0);
}
