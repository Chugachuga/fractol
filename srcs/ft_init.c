/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 19:32:38 by gvilmont          #+#    #+#             */
/*   Updated: 2016/06/17 19:55:35 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandel(t_z *z)
{
	z->x1 	= -2.1;
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
	z->x2 	= 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 100;
	z->imax = 150;
	z->ix = (z->x2 - z->x1) * z->zoom;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init_mandelbis(t_z *z)
{
	z->x1 = -2.1;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = 100;
	z->imax = 100;
	z->ix = (z->x2 - z->x1) * z->zoom;
	z->iy = (z->y2 - z->y1) * z->zoom;
}

void	ft_init_bship(t_z *z)
{
	z->x1 = -2.1;
	z->x2 = 0.6;
	z->y1 = -1.5;
	z->y2 = 1.2;
	z->zoom = 100;
	z->imax = 100;
	z->ix = (z->x2 - z->x1) * z->zoom;
	z->iy = (z->y2 - z->y1) * z->zoom;
}
