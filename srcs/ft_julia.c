/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:32:21 by gvilmont          #+#    #+#             */
/*   Updated: 2016/09/29 16:04:04 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_juliab(t_z *z)
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
				z->z_r = tan(z->z_r * z->z_r - z->z_i * z->z_i + z->c_r);
				z->z_i = 2 * tan(z->z_i * z->tmp + z->c_i);
				z->i++;
			}
			if (z->i == z->imax)
				put_pixel_to_image(z->x, z->y, z, 2);
			else
				put_pixel_to_image(z->x, z->y, z, 1);
		}
	}
}

void	ft_init_juliab(t_z *z)
{
	z->x1 = -1.6;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 250;
	z->ix = (z->x2 - z->x1) * z->zoom + 150;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_do_juliab(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "JuliaBis");
	ft_juliab(z);
}

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

int		ft_julia_hook(int x, int y, t_z *z)
{
	if ((!(ft_strcmp(z->argv, "julia")) || !(ft_strcmp(z->argv, "juliab")))
			&& x <= WIN_X && y <= WIN_Y && x > 0 && y > 0)
	{
		z->c_r = (float)(x + 400 - WIN_X) / 300;
		z->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (1);
}
