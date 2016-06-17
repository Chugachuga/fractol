/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/17 19:59:51 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init(t_z	*z)
{
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, 1000, 1000, "Fractol");
	if (z->f == 2)
		ft_do_mandel(z);
	if (z->f == 1)
		ft_do_julia(z);
	if (z->f == 3)
		ft_do_mandelbis(z);
	if (z->f == 4)
		ft_do_bship(z);
}

int		ft_choose(char *str)
{
	if (ft_strcmp(str, "julia") == 0)
		return (1);
	if (ft_strcmp(str, "mandelbrot") == 0)
		return (2);
	if (ft_strcmp(str, "mandelbis") == 0)
		return (3);
	if (ft_strcmp(str, "burningship") == 0)
		return (4);
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
