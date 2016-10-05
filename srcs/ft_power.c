/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:20:08 by gvilmont          #+#    #+#             */
/*   Updated: 2016/10/04 15:21:23 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_power(t_z *z)
{
	z->tmp = pow(z->z_r * z->z_r + z->z_i * z->z_i, z->pow / 2) *
					cos(z->pow * atan2(z->z_r, z->z_i)) + z->c_r;
	z->z_i = -pow(z->z_r * z->z_r + z->z_i * z->z_i, z->pow / 2) *
					sin(z->pow * atan2(z->z_r, z->z_i)) + z->c_i;
	z->z_r = z->tmp;
}
