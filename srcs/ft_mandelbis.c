/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:44:01 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/17 20:00:47 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbis(t_z *z)
{
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
			while (z->z_r * z->z_r + z->z_i * z->z_i < 4 && z->i < z->imax)
			{
				z->tmp = z->z_r;
				z->z_r = z->z_r * z->z_r - z->z_i * z->z_i + z->c_r;
				z->z_i = -2 * z->z_i * z->tmp + z->c_i;
				z->i++;
			}
			if (z->i == z->imax)
				put_pixel_to_image(z->x, z->y, z, 2);
			else
				put_pixel_to_image(z->x, z->y, z, 1);
		}
	}
}

void	ft_burningship(t_z *z)
{
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
			while (z->z_r * z->z_r + z->z_i * z->z_i < 4 && z->i < z->imax)
			{
				z->tmp = z->z_r;
				z->z_r = z->z_r * z->z_r - z->z_i * z->z_i + z->c_r;
				z->z_i = 2 * fabs(z->z_i * z->tmp) + z->c_i;
				z->i++;
			}
			if (z->i == z->imax)
				put_pixel_to_image(z->x, z->y, z, 2);
			else
				put_pixel_to_image(z->x, z->y, z, 1);
		}
	}
}
