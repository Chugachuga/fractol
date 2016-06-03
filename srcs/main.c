/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/03 16:47:18 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init(t_z	*z)
{
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, 1000, 1000, "Fractol");
	mlx_string_put(z->mlx, z->win, 10, 10, 0x00FFFFFF, "fractol");
	z->imax = 50;
	z->x1 = -2.1;
	z->x2 = 0.6;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 250;
	z->ix = (z->x2 - z->x1) * z->zoom;
	z->iy = (z->y2 - z->y1) * z->zoom;
	z->img = mlx_new_image(z->mlx, z->ix, z->iy);
	z->img_data = mlx_get_data_addr(z->img, &(z->bit_per_pixel), &(z->s_line),
			&(z->ed));
	if (z->f == 2)
		ft_mandelbrot(z);
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
