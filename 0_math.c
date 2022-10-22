/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_math.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 11:08:20 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/16 10:20:16 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mat_limits(float mat, float *max, float *min)
{
	if (mat > *max)
		*max = mat;
	if (mat < *min)
		*min = mat;
}

int	sign(float nb)
{
	return (-(nb < 0) + (nb >= 0));
}

int	ft_abs(float nb)
{
	return (-(nb < 0) * nb + (nb >= 0) * nb);
}
