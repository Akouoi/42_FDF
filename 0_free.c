/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:08:10 by akouoi            #+#    #+#             */
/*   Updated: 2022/10/10 12:31:23 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_clear_mat(float **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_clear_pix(t_pix **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	ft_clean_mlx(t_data data)
{
	if (data.img.mlx_img)
		mlx_destroy_image(data.mlx, data.img.mlx_img);
	if (data.win)
		mlx_destroy_window(data.mlx, data.win);
	if (data.mlx)
		mlx_destroy_display(data.mlx);
	return (ft_clean_error(&data));
}

int	ft_clean(t_data *data)
{
	if (data->lst)
		ft_lstclear(data->lst, free);
	if (data->mat)
		ft_clear_mat(data->mat);
	if (data->pix)
		ft_clear_pix(data->pix);
	if (data->file)
		free(data->file);
	if (data->arg)
		free(data->arg);
	free(data);
	return (0);
}

int	ft_clean_error(t_data *data)
{
	ft_printf("Error\n");
	ft_clean(data);
	exit(0);
}
