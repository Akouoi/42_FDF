/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:10:37 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/19 12:41:30 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2 || !(*av[1]))
		return (ft_printf("ERROR : Enter valid arguments\n"));
	data = init_data();
	if (get_data(data, av) == 1 || !(*(data->lst)))
		return (ft_clean_error(data));
	init_mat_pix(data);
	get_pix(data);
	find_min(data);
	define_window(data);
	show(*data);
	return (ft_clean(data));
}
