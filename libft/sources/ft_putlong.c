/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 20:30:27 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 19:17:02 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putlong(long n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9223372036854775807)
		{
			ft_putlong(922337203685477580);
			n = -8;
		}
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putlong(n / 10);
		ft_putlong(n % 10);
	}
	else
		ft_putchar(n + '0');
}
