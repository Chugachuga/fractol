/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:24:27 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/03 16:44:55 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel_to_image(int x, int y, t_z *z)
{
	if (x <= z->ix && y <= z->iy && x > 0 && y > 0)
		*(unsigned int*)(z->img_data + ((int)(z->bit_per_pixel *
				(x)) + z->s_line * (y))) = z->i * 1899750;
}

void	ft_mandelbrot(t_z *z)
{
	double	tmp;

	z->x = -1;
	while (++z->x < z->ix)
	{
		z->y = -1;
		while (++z->y < z->iy)
		{
			z->c_r = z->x / z->zoom + z->x1;
			z->c_i = z->y / z->zoom + z->y1;
			z->z_r = 0;
			z->z_i = 0;
			z->i = 0;
			while (z->z_r * z->z_r + z->z_i * z->z_i < 4
				&& z->i < z->imax)
			{
				tmp = z->z_r;
				z->z_r = z->z_r * z->z_r - z->z_i * z->z_i + z->c_r;
				z->z_i = 2 * z->z_i * tmp + z->c_i;
				z->i++;
			}
			if (z->i == z->imax)
				put_pixel_to_image(z->x, z->y, z);
			else
				put_pixel_to_image(z->x, z->y, z);
		}
	}
}
