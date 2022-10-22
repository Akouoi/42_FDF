/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:40:29 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/27 19:06:41 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <X11/keysym.h>
# include <math.h>
# include <limits.h>
# include "mlx_Linux/mlx.h"
# include "fdf_struct.h"
# include "fdf_macro.h"

//-----------------------------------------		0_free.c
int		ft_clean(t_data *data);
int		ft_clear_mat(float **tab);
int		ft_clear_pix(t_pix **tab);
int		ft_clean_error(t_data *data);
int		ft_clean_mlx(t_data data);
//-----------------------------------------		0_math.c
void	mat_limits(float mat, float *max, float *min);
int		ft_abs(float nb);
int		sign(float nb);
//-----------------------------------------		0_print.c
int		print_data(t_data *data);
int		print_param(t_list **lst);
//-----------------------------------------		1_init.c
t_data	*init_data(void);
void	init_mat_pix(t_data *data);
//-----------------------------------------		2_parsing.c
int		check_atoi(const char *str);
int		check_number(char *str);
int		check_arg(char *str, t_data *data);
int		get_data(t_data *data, char **av);
//-----------------------------------------		3_define_window.c
void	center(t_data *data);
void	define_window(t_data *data);
//-----------------------------------------		3_get_coord.c
void	find_min(t_data *data);
t_pix	get_point(float mat, int x, int y);
int		get_col(t_data *data, int x, int y);
int		get_pix(t_data *data);
//-----------------------------------------		4_show.c
int		check_pixel(int x, int y);
void	img_pix_put(t_img *img, int x, int y, int color);
int		render(t_data *data);
void	ft_mlx_loop(t_data data);
int		show(t_data data);
//-----------------------------------------		5_line.c
int		render_line(t_data *data);
void	line_calc_1(t_img *img, t_pix start, t_pix end);
void	line_calc_2(t_img *img, t_pix start, t_pix end);
void	line_x(t_data *data, int x0, int y0);
void	line_y(t_data *data, int x0, int y0);
//-----------------------------------------		6_event.c
int		fdf_close(int keycode, t_data *data);
int		change_col(int keycode, t_data *data);
int		key_hooks(int keycode, t_data *data);
int		mouse_hooks(int keycode, int x, int y, t_data *data);
//-----------------------------------------		rotate.c
int		rotate(t_data *data);

#endif