/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:27:00 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/03 16:41:43 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_z
{
	int			f;
	float		z_r;
	float		z_i;
	float		c_r;
	float		c_i;
	int			i;
	int			imax;
	int			x;
	int			y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		ix;
	float		iy;
	float		zoom;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bit_per_pixel;
	int			s_line;
	int			ed;
	int			color;
}				t_z;

void			ft_mandelbrot(t_z *z);
#endif
