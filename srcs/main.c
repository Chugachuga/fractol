/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/08/31 20:13:42 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_choose(t_z *z)
{
	if (ft_strcmp(z->argv, "julia") == 0)
		return (1);
	if (ft_strcmp(z->argv, "mandelbrot") == 0)
		return (2);
	if (ft_strcmp(z->argv, "mandelbis") == 0)
		return (3);
	if (ft_strcmp(z->argv, "burningship") == 0)
		return (4);
	else
	{
		ft_putstr("**ERROR, julia, mandelbrot,\n");
		ft_putstr("mandelbis and burningship\n");
		ft_putstr("available only**\n");
	}
	return (0);
}

void	fractol(t_z *z)
{
	if (z->f == 1)
		ft_do_julia(z);
	if (z->f == 2)
		ft_do_mandel(z);
	if (z->f == 3)
		ft_do_mandelbis(z);
	if (z->f == 4)
		ft_do_bship(z);
}

int		ft_core(t_z *z)
{
	mlx_destroy_image(z->mlx, z->img);
	z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
	fractol(z);
	mlx_put_image_to_window(z->mlx, z->win, z->img, 0, 40);
	return (1);
}

int		ft_keyhook(int keycode, t_z *z)
{
	if (keycode == 53)
	{
		free(z);
		exit(0);
	}
	if (keycode == 0)
		z->color = 1;
	if (keycode == 1)
		z->color = 2;
	if (keycode == 69)
		z->imax += 5;
	if (keycode == 78)
		z->imax -= 5;
	if (keycode == 18 || keycode == 19)
	{
		mlx_clear_window(z->mlx, z->win);
		z->argv = (keycode == 18 ? "mandelbrot" : "julia");
	}
	if (keycode == 20 || keycode == 21)
	{
		mlx_clear_window(z->mlx, z->win);
		z->argv = (keycode == 20 ? "mandelbis" : "burningship");
	}
	z->f = ft_choose(z);
	return (1);
}

int		main(int ac, char *av[])
{
	t_z *z;

	if (!(z = (t_z*)malloc(sizeof(t_z))))
		return (0);
	if (ac != 2)
	{
		ft_putstr("**ERROR, too many/few argument**\n");
		ft_putstr("mandelbrot, mandelbis, julia, burningship\n");
		return (0);
	}
	z->argv = av[1];
	if ((z->f = ft_choose(z)))
	{
		z->color = 1;
		z->imax = 40;
		ft_menu();
		z->mlx = mlx_init();
		z->win = mlx_new_window(z->mlx, WIN_X, WIN_Y, "Fractol");
		z->img = mlx_new_image(z->mlx, WIN_X, WIN_Y);
		mlx_hook(z->win, 2, 1, ft_keyhook, z);
		mlx_hook(z->win, 6, (1L << 6), ft_julia_hook, z);
		mlx_loop_hook(z->mlx, ft_core, z);
		mlx_loop(z->mlx);
	}
	return (0);
}
