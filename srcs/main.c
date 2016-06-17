/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/17 18:30:17 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandel(t_z *z)
{
	z->x1 = -2.1;
	z->x2 = 0.6;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 100;
	z->imax = 50;
	z->ix = (z->x2 - z->x1) * z->zoom;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init_julia(t_z *z)
{
	z->x1 = -1;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 100;
	z->imax = 150;
	z->ix = (z->x2 - z->x1) * z->zoom;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_do_mandel(t_z *z)
{
	ft_init_mandel(z);
	z->img = mlx_new_image(z->mlx, z->ix, z->iy);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Mandelbrot");
	ft_mandelbrot(z);
}

void	ft_do_julia(t_z *z)
{
	ft_init_julia(z);
	z->img = mlx_new_image(z->mlx, z->ix, z->iy);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "Julia");
	ft_julia(z);
}

void	ft_init(t_z	*z)
{
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, 1000, 1000, "Fractol");
	if (z->f == 2)
		ft_do_mandel(z);
	if (z->f == 1)
		ft_do_julia(z);
}

int		ft_choose(char *str)
{
	if (ft_strcmp(str, "julia") == 0)
		return (1);
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (2);
	else
	{
		ft_putstr("**ERROR, julia or mandelbrot available only**\n");
		return (0);
	}
}

int		main(int ac, char *av[])
{
	t_z *z;
	if (!(z = (t_z*)malloc(sizeof(t_z))))
		return (0);
	if (ac != 2)
	{
		ft_putstr("**ERROR, too many/few argument**\n");
		return (0);
	}
	if ((z->f = ft_choose(av[1])))
	{
		ft_init(z);
		mlx_put_image_to_window(z->mlx, z->win, z->img, 40, 40);
		mlx_loop(z->mlx);
	}
	return (0);
}
