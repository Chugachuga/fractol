/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:32:38 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/05 14:47:05 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandel(t_z *z)
{
	z->x1 = -2.1;
	z->x2 = 0.6;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 260;
	z->ix = (z->x2 - z->x1) * z->zoom + 100;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init_julia(t_z *z)
{
	z->x1 = -1.6;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 250;
	z->ix = (z->x2 - z->x1) * z->zoom + 150;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init_mandelbis(t_z *z)
{
	z->x1 = -2.1;
	z->x2 = 1;
	z->y1 = -1.3;
	z->y2 = 1.3;
	z->zoom = 230;
	z->ix = (z->x2 - z->x1) * z->zoom + 300;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init_bship(t_z *z)
{
	z->x1 = -2.1;
	z->x2 = 1;
	z->y1 = -1.5;
	z->y2 = 1.2;
	z->zoom = 250;
	z->ix = (z->x2 - z->x1) * z->zoom + 50;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init(t_z *z)
{
	z->color = 1;
	z->imax = 40;
	if (z->f == 1)
		ft_init_julia(z);
	if (z->f == 2)
		ft_init_mandel(z);
	if (z->f == 3)
		ft_init_mandelbis(z);
	if (z->f == 4)
		ft_init_bship(z);
	if (z->f == 5)
		ft_init_juliab(z);
	if (z->f == 6)
		ft_init_mandelpow(z);
}
