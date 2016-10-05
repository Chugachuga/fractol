/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:27:00 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/04 16:03:06 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

# define WIN_X 800
# define WIN_Y 640

typedef struct	s_z
{
	float		xad;
	float		yad;
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
	float		y1;
	float		x2;
	float		y2;
	int			ix;
	int			iy;
	float		tmp;
	float		tmpx;
	float		tmpx2;
	float		tmpy;
	float		tmpy2;
	float		zoom;
	float		zoomx;
	float		zoomy;
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			bit_per_pixel;
	int			s_line;
	int			ed;
	int			color;
	char		*argv;
	int			pow;
}				t_z;

void			ft_power(t_z *z);
int				ft_keypow(int keycode, t_z *z);
void			ft_pow(t_z *z);
void			ft_init_mandelpow(t_z *z);
void			ft_mandelpow(t_z *z);
void			ft_do_mandelpow(t_z *z);
void			ft_init_juliab(t_z *z);
void			ft_juliab(t_z *z);
void			ft_do_juliab(t_z *z);
int				ft_choose(t_z *z);
void			ft_new(t_z *z);
void			ft_errors(t_z *z);
void			ft_init(t_z *z);
void			ft_value(t_z *z);
void			ft_menu();
void			ft_init_mandelbis(t_z *z);
void			ft_init_mandel(t_z *z);
void			ft_init_julia(t_z *z);
void			ft_init_bship(t_z *z);
void			ft_do_mandel(t_z *z);
void			ft_do_mandelbis(t_z *z);
void			ft_do_julia(t_z *z);
void			ft_do_bship(t_z *z);
void			ft_mandelbrot(t_z *z);
void			ft_julia(t_z *z);
int				ft_julia_hook(int x, int y, t_z *z);
int				ft_mouse_hook(int button, int x, int y, t_z *z);
void			ft_mandelbis(t_z *z);
void			ft_burningship(t_z *z);
void			put_pixel_to_image(int x, int y, t_z *z, int a);
#endif
