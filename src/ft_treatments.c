/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:50:31 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/20 13:17:37 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_dec(char *nbr_c)
{
	int	nbr;

	nbr = ft_atoi(nbr_c);
	if (nbr == 0 || nbr == -1)
		return (0);
	return (ft_base(nbr, 10, 0));
}

int	ft_treat_void(unsigned long long nbr)
{
	int	c;

	c = 0;
	c += ft_putstr("0x");
	c += ft_base((unsigned long long)(nbr), 16, 1);
	return (c);
}
