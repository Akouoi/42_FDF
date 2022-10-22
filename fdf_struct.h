/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:46:28 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/19 08:02:41 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

//-----------------------------------------		points
typedef struct s_pix
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	int			c;
}	t_pix;
//-----------------------------------------		donnees
typedef struct s_arg
{
	float		max_mat;
	float		min_mat;

	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;

}	t_arg;
//-----------------------------------------		image
typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			len;
	int			end;
}	t_img;
//-----------------------------------------		parametres affichage
typedef struct s_par
{
	float	rho;
}	t_par;
//-----------------------------------------		data
typedef struct s_data
{
	int			bg_col;

	void		*mlx;
	void		*win;
	t_img		img;

	t_arg		*arg;
	t_par		par;

	char		*file;
	t_list		**lst;

	int			lx;
	int			ly;
	float		**mat;
	t_pix		**pix;
}	t_data;

#endif