/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 19:34:45 by gvilmont          #+#    #+#             */
/*   Updated: 2016/08/31 19:56:06 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_menu(void)
{
	ft_putstr("\n\n      F  R  A  C  T  0  L     ");
	ft_putstr("\n     #####################     ");
	ft_putstr("\n             MENU             ");
	ft_putstr("\n     #####################     ");
	ft_putstr("\n     KEY            EFFECT");
	ft_putstr("\n     ---------------------");
	ft_putstr("\n     1 - 2         Switch");
	ft_putstr("\n     3 - 4         Fractol");
	ft_putstr("\n     ---------------------");
	ft_putstr("\n     A      Original Color");
	ft_putstr("\n     S          Blue Color");
	ft_putstr("\n     ---------------------");
	ft_putstr("\n     ESC              Exit\n\n");
	return ;
}
