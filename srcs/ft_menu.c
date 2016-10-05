/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 19:34:45 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/05 15:25:10 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_menu(void)
{
	ft_putstr("\n\n         F  R  A  C  T  0  L  ");
	ft_putstr("\n     ###########################");
	ft_putstr("\n                 MENU           ");
	ft_putstr("\n     ###########################");
	ft_putstr("\n     KEY                  EFFECT");
	ft_putstr("\n     ---------------------------");
	ft_putstr("\n     1 - 2                      ");
	ft_putstr("\n     3 - 4                Switch");
	ft_putstr("\n     5 - 6               Fractol");
	ft_putstr("\n     7 - 8                      ");
	ft_putstr("\n     ---------------------------");
	ft_putstr("\n     A            Original Color");
	ft_putstr("\n     S                Blue Color");
	ft_putstr("\n     ---------------------------");
	ft_putstr("\n     +        Increase Iteration");
	ft_putstr("\n     -        Decrease Iteration");
	ft_putstr("\n     ---------------------------");
	ft_putstr("\n     Arrow                  Move");
	ft_putstr("\n     ---------------------------");
	ft_putstr("\n     Wheel              Zoom In ");
	ft_putstr("\n     Mouse              Zoom Out");
	ft_putstr("\n     ---------------------------");
	ft_putstr("\n     ESC                    Exit\n\n");
	return ;
}

void		ft_zoomin(int x, int y, t_z *z)
{
	z->zoom *= 2;
	z->tmpx = z->x1 + x * (z->x2 - z->x1) / WIN_X;
	z->tmpy = z->y1 + y * (z->y2 - z->y1) / WIN_Y;
	z->tmpx2 = z->x1;
	z->tmpy2 = z->y1;
	z->x1 = z->tmpx - (z->x2 - z->x1) / 4;
	z->x2 = z->tmpx + (z->x2 - z->tmpx2) / 4;
	z->y1 = z->tmpy - (z->y2 - z->y1) / 4;
	z->y2 = z->tmpy + (z->y2 - z->tmpy2) / 4;
}

void		ft_zoomout(int x, int y, t_z *z)
{
	if (z->zoom > 250)
	{
		z->zoom /= 2;
		z->tmpx = z->x1 + x * (z->x2 - z->x1) / WIN_X;
		z->tmpy = z->y1 + y * (z->y2 - z->y1) / WIN_Y;
		z->tmpx2 = z->x1;
		z->tmpy2 = z->y1;
		z->x1 = z->tmpx - (z->x2 - z->x1);
		z->x2 = z->tmpx + (z->x2 - z->tmpx2);
		z->y1 = z->tmpy - (z->y2 - z->y1);
		z->y2 = z->tmpy + (z->y2 - z->tmpy2);
	}
}

int			ft_mouse_hook(int button, int x, int y, t_z *z)
{
	if (y > 0)
	{
		if (button == 5)
			ft_zoomin(x, y, z);
		if (button == 4)
			ft_zoomout(x, y, z);
	}
	return (1);
}

void		ft_errors(t_z *z)
{
	free(z);
	ft_putstr("**ERROR, too many/few argument**\n");
	ft_putstr("mandelbrot, mandelbis, julia, burningship\njuliab");
	ft_putstr("mandelpow1, mandelpow2, mandelpow3**\n");
	return ;
}
