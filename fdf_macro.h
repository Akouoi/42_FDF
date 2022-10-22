/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_macro.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouoi <akouoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:22:13 by akouoi            #+#    #+#             */
/*   Updated: 2022/09/21 06:33:47 by akouoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MACRO_H
# define FDF_MACRO_H

//-----------------------------------------		parameters
# define WIN_WID		1900
# define WIN_HEI		1000
# define IMG_WID		3000
# define IMG_HEI		3000

# define S			50
//-----------------------------------------		colors
# define WHITE 		0xFFFFFF
# define RED		0xFF0000
# define BLACK		0x000000
# define D_RED		0x652600
# define ORANGE 	0xEA7B24
# define YELLOW 	0xDFD633
# define GREEN		0x004204
# define BLUE 		0x9546F7
//-----------------------------------------		keycodes
enum e_moves
{
	left = 65361,
	right = 65363,
	up = 65362,
	down = 65364
};

//-----------------------------------------		print colors
# define GREEN_B		"\033[32;01m"
# define WHITE_B		"\033[37;01m"
# define GREEN_S		"\033[32;02m"
# define GREEN_I		"\033[32;03m"
# define GREEN_U		"\033[32;04m"

# define RED_B			"\033[31;01m"
# define COL			"\033[00m"

#endif

// Couleurs pour print
// \033[33;01mjaune\033[00m
// \033[34;01mbleu\033[00m
// \033[35;01mviolet\033[00m
// \033[36;01mturquoise\033[00m
// \033[37;01mblanc\033[00m
