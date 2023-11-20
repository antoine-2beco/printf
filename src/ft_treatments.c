/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:50:31 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/20 14:40:59 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_dec(long long int nbr)
{
	int	c;

	c = 0;
	if (nbr < 0)
	{
		c += ft_putchar('-');
		nbr *= -1;
	}
	return (ft_base(nbr, 10, 0) + c);
}

int	ft_treat_void(long long int nbr)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	c += ft_base((unsigned long long)(nbr), 16, 1);
	return (c);
}

int	ft_treat_hexa(long long int nbr, int lower)
{
	int	c;

	c = 0;
	if (nbr < 0)
	{
		c += ft_putchar('-');
		nbr *= -1;
	}
	if (lower)
		return (ft_base(nbr, 16, 1) + c);
	else
		return (ft_base(nbr, 16, 0) + c);
}
