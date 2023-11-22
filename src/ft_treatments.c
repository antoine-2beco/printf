/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:50:31 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/22 23:36:21 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_dec(long long int nbr)
{
	int	c;
	int	j;

	c = 0;
	if (nbr < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nbr *= -1;
		c++;
	}
	j = ft_base(nbr, 10, 0);
	if (j == -1)
		return (-1);
	return (c + j);
}

int	ft_treat_void(long long int nbr)
{
	int	j;

	if (ft_putstr("0x", 0) == -1)
		return (-1);
	j = ft_base((unsigned long long)nbr, 16, 1);
	if (j == -1)
		return (-1);
	return (2 + j);
}
