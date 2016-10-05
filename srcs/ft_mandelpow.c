/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelpow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:58:33 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/05 15:15:54 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_pow(t_z *z)
{
	if (ft_strcmp(z->argv, "mandelpow1") == 0)
		z->pow = 96;
	if (ft_strcmp(z->argv, "mandelpow2") == 0)
		z->pow = 4;
	if (ft_strcmp(z->argv, "mandelpow3") == 0)
		z->pow = 6;
}

void	ft_init_mandelpow(t_z *z)
{
	z->x1 = -2;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 250;
	z->ix = (z->x2 - z->x1) * z->zoom + 50;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_mandelpow(t_z *z)
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
				ft_power(z);
				z->i++;
			}
			if (z->i == z->imax)
				put_pixel_to_image(z->x, z->y, z, 2);
			else
				put_pixel_to_image(z->x, z->y, z, 1);
		}
	}
}

void	ft_do_mandelpow(t_z *z)
{
	mlx_clear_window(z->mlx, z->win);
	z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	if (z->pow == 96)
		mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Mandelpow1");
	if (z->pow == 4)
		mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Mandelpow2");
	if (z->pow == 6)
		mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Mandelpow3");
	ft_mandelpow(z);
}

int		ft_keypow(int keycode, t_z *z)
{
	if (keycode == 22 || keycode == 26)
	{
		z->argv = keycode == 22 ? "mandelpow1" : "mandelpow2";
		ft_new(z);
	}
	if (keycode == 28 || keycode == 23)
	{
		z->argv = keycode == 28 ? "mandelpow3" : "juliab";
		ft_new(z);
	}
	if (keycode == 123)
		z->xad -= 0.01;
	if (keycode == 124)
		z->xad += 0.01;
	if (keycode == 125)
		z->yad += 0.01;
	if (keycode == 126)
		z->yad -= 0.01;
	return (1);
}
