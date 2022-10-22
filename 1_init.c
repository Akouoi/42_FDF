/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 09:37:16 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/18 18:18:44 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof (t_data));
	if (!data)
		exit(0);
	data->arg = malloc (sizeof(t_arg));
	if (!data->arg)
		ft_clean_error(data);
	data->lx = 0;
	data->ly = 0;
	data->lst = malloc(sizeof (t_list));
	if (!data->lst)
		ft_clean_error(data);
	*(data->lst) = NULL;
	data->mat = NULL;
	data->pix = NULL;
	data->mlx = NULL;
	data->win = NULL;
	return (data);
}

void	init_mat_pix(t_data *data)
{
	data->mat = malloc (sizeof (float *) * (data->ly + 1));
	if (!data->mat)
		ft_clean_error(data);
	data->pix = malloc (sizeof (t_pix *) * (data->ly + 1));
	if (!data->pix)
		ft_clean_error(data);
	data->bg_col = GREEN;
	data->par.rho = M_PI_2 * 2 / 6;
}
