/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_show.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:52:02 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/19 12:40:39 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_pixel(int x, int y)
{
	if (x >= WIN_WID || x < 0)
		return (1);
	if (y >= WIN_HEI || y < 0)
		return (1);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pix;

	pix = img->addr + (y * img->len + x * (img->bpp / 8));
	*(int *)pix = color;
}

int	render(t_data *data)
{
	int	y;
	int	x;

	if (data->win == NULL)
		return (ft_clean(data), 1);
	y = 0;
	while (y < WIN_HEI)
	{
		x = 0;
		while (x < WIN_WID)
		{
			if (check_pixel(x, y) == 0)
				img_pix_put(&data->img, x, y, data->bg_col + y / 10 + x / 30);
			x++;
		}
		++y;
	}
	render_line(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	print_data(data);
	return (0);
}

void	ft_mlx_loop(t_data data)
{
	mlx_key_hook(data.win, key_hooks, &data);
	mlx_hook(data.win, 2, 1L << 0, fdf_close, data.mlx);
	mlx_hook(data.win, 17, 1L << 0, mlx_loop_end, data.mlx);
	mlx_mouse_hook(data.win, mouse_hooks, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
}

int	show(t_data data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
		return (-1 * (ft_printf("where is mlx ?\n")));
	data.win = mlx_new_window(data.mlx, WIN_WID, WIN_HEI, data.file);
	if (!data.win)
		ft_clean_mlx(data);
	data.img.mlx_img = mlx_new_image(data.mlx, IMG_WID, IMG_HEI);
	if (!data.img.mlx_img)
		ft_clean_mlx(data);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
		&data.img.len, &data.img.end);
	if (!data.img.addr)
		ft_clean_mlx(data);
	ft_mlx_loop(data);
	mlx_destroy_image(data.mlx, data.img.mlx_img);
	mlx_destroy_window(data.mlx, data.win);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}
