/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:24:27 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/05 15:12:53 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel_to_image(int x, int y, t_z *z, int a)
{
	if (x <= z->ix && y <= z->iy && x > 0 && y > 0)
	{
		if (a == 1)
		{
			if (z->color == 1)
			{
				*(int*)(z->img_data + ((int)((z->bit_per_pixel / 8) *
						(x)) + z->s_line * (y))) = z->i * 1899750;
			}
			if (z->color == 2)
			{
				*(int*)(z->img_data + ((int)((z->bit_per_pixel / 8) *
						(x)) + z->s_line * (y))) = z->i * 255 / z->imax;
			}
		}
		if (a == 2)
		{
			*(int*)(z->img_data + ((int)((z->bit_per_pixel / 8) *
					(x)) + z->s_line * (y))) = 0x000000;
		}
	}
}

void	ft_mandelbrot(t_z *z)
{
	z->x = -1;
	while (++z->x < z->ix)
	{
		z->y = -1;
		while (++z->y < z->iy)
		{
			z->c_r = z->x / z->zoom + z->x1 + z->xad;
			z->c_i = z->y / z->zoom + z->y1 + z->yad;
			z->z_r = 0;
			z->z_i = 0;
			z->i = 0;
			while (z->z_r * z->z_r + z->z_i * z->z_i < 4 && z->i < z->imax)
			{
				z->tmp = z->z_r;
				z->z_r = z->z_r * z->z_r - z->z_i * z->z_i + z->c_r;
				z->z_i = 2 * z->z_i * z->tmp + z->c_i;
				z->i++;
			}
			if (z->i == z->imax)
				put_pixel_to_image(z->x, z->y, z, 2);
			else
				put_pixel_to_image(z->x, z->y, z, 1);
		}
	}
}
