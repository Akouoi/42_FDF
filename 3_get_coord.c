/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_get_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:10:40 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/16 10:49:57 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_min(t_data *data)
{
	int	x;
	int	y;

	data->arg->min_x = INT_MAX;
	data->arg->min_y = INT_MAX;
	data->arg->max_x = INT_MIN;
	data->arg->max_y = INT_MIN;
	y = 0;
	while (y < data->ly)
	{
		x = 0;
		while (x < data->lx)
		{
			if (data->pix[y][x].x < data->arg->min_x)
				data->arg->min_x = data->pix[y][x].x;
			if (data->pix[y][x].y < data->arg->min_y)
				data->arg->min_y = data->pix[y][x].y;
			if (data->pix[y][x].x > data->arg->max_x)
				data->arg->max_x = data->pix[y][x].x;
			if (data->pix[y][x].y > data->arg->max_y)
				data->arg->max_y = data->pix[y][x].y;
			x++;
		}
		y++;
	}
}

int	convert_data(t_data *data)
{
	int		i;
	int		j;
	char	**tab;
	t_list	*tmp;

	tmp = *(data->lst);
	i = -1;
	while (++i < data->ly)
	{
		tab = ft_split(tmp->content, ' ');
		data->mat[i] = malloc (sizeof (float) * (data->lx + 1));
		if (!data->mat[i])
			return (ft_clean_error(data));
		j = -1;
		while (tab[++j])
		{
			data->mat[i][j] = (float)ft_atoi(tab[j]);
			mat_limits(data->mat[i][j], &(data->arg->max_mat), \
				&(data->arg->min_mat));
		}
		tmp = tmp->next;
		ft_clear(tab);
	}
	return (data->mat[i] = NULL, 0);
}

t_pix	get_point(float mat, int x, int y)
{
	t_pix	pix;

	pix.x = sqrt(2) * (x - y) / 2;
	pix.y = (x + y) / sqrt(6) - sqrt(2) * mat / 2;
	return (pix);
}

int	get_col(t_data *data, int x, int y)
{
	int	dc;

	dc = data->arg->max_mat - data->arg->min_mat;
	if (data->mat[y][x] == data->arg->min_mat)
		return (RED);
	else
		return (RED + ((data->mat[y][x] - data->arg->min_mat) \
			* (WHITE - RED) / dc));
}

int	get_pix(t_data *data)
{
	int	x;
	int	y;

	data->arg->min_mat = INT_MAX;
	data->arg->max_mat = INT_MIN;
	convert_data(data);
	y = 0;
	while (y < data->ly)
	{
		data->pix[y] = malloc (sizeof (t_pix) * (data->lx));
		if (!data->pix[y])
			return (ft_clean_error(data));
		x = 0;
		while (x < data->lx)
		{
			data->pix[y][x] = get_point(data->mat[y][x], x, y);
			data->pix[y][x].c = get_col(data, x, y);
			x++;
		}
		y++;
	}
	data->pix[y] = NULL;
	return (0);
}
