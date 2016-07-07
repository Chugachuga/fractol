/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:32:21 by gvilmont          #+#    #+#             */
/*   Updated: 2016/07/07 16:40:04 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_julia(t_z *z)
{
	z->x = -1;
	while (++z->x < z->ix)
	{
		z->y = -1;
		while (++z->y < z->iy)
		{
			z->z_r = z->x / z->zoom + z->x1;
			z->z_i = z->y / z->zoom + z->y1;
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

int        ft_julia_hook(int x, int y, t_z *z)
{
	if (!(ft_strcmp(z->argv, "julia")) &&
			x <= WIN_X && y <= WIN_Y && x > 0 && y > 0)
	{
		z->c_r = (float)(x + 400 - WIN_X) / 300;
		z->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (1);
}
