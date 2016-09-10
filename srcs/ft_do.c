/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:35:40 by gvilmont          #+#    #+#             */
/*   Updated: 2016/09/10 19:45:30 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_do_mandel(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Mandelbrot");
	ft_mandelbrot(z);
}

void	ft_do_mandelbis(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->img = mlx_new_image(z->mlx, z->ix, z->iy);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Mandelbis");
	ft_mandelbis(z);
}

void	ft_do_julia(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->img = mlx_new_image(z->mlx, z->ix, z->iy);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Julia");
	ft_julia(z);
}

void	ft_do_bship(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->img = mlx_new_image(z->mlx, z->ix, z->iy);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Burning Ship");
	ft_burningship(z);
}

void	ft_new(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->f = ft_choose(z);
	ft_init(z);
	return ;
}
