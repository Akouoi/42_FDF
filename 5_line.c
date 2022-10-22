/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:07:19 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/19 12:12:15 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render_line(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->ly)
	{
		x = 0;
		while (x < data->lx)
		{
			if (x < data->lx - 1)
				line_x(data, x, y);
			if (y < data->ly - 1)
				line_y(data, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	line_calc_1(t_img *img, t_pix start, t_pix end)
{
	float	x;
	float	b;

	start.dx = end.x - start.x;
	start.dy = end.y - start.y;
	x = start.x;
	b = start.y - start.dy / start.dx * start.x;
	while (round(x) != round(end.x))
	{
		if (check_pixel(x, x * start.dy / start.dx + b) == 0)
			img_pix_put(img, x, x * start.dy / start.dx + b, \
				start.c + (x - start.x) * (end.c - start.c) / (start.dx));
		x += sign(start.dx);
	}
}

void	line_calc_2(t_img *img, t_pix start, t_pix end)
{
	float	y;
	float	b;

	start.dx = end.x - start.x;
	start.dy = end.y - start.y;
	y = start.y;
	b = start.x - start.dx / start.dy * start.y;
	while (round(y) != round(end.y))
	{
		if (check_pixel(y * start.dx / start.dy + b, y) == 0)
			img_pix_put(img, y * start.dx / start.dy + b, y, \
				(start.c + (y - start.y) * (end.c - start.c) / (start.dy)));
		y += sign(start.dy);
	}
}

void	line_y(t_data *data, int x0, int y0)
{
	t_pix	start;
	t_pix	end;

	start = data->pix[y0][x0];
	end = data->pix[y0 + 1][x0];
	if (ft_abs((end.y - start.y) / (end.x - start.x)) < 1 && end.x < start.x)
		line_calc_1(&data->img, start, end);
	else
		line_calc_2(&data->img, end, start);
}

void	line_x(t_data *data, int x0, int y0)
{
	t_pix	start;
	t_pix	end;

	start = data->pix[y0][x0];
	end = data->pix[y0][x0 + 1];
	if (ft_abs((end.y - start.y) / (end.x - start.x)) < 1)
		line_calc_1(&data->img, start, end);
	else
		line_calc_2(&data->img, start, end);
}
