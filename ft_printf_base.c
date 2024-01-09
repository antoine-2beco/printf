/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:29:59 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/09 17:56:42 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenght_nbr(unsigned long long nbr, int base_lenght)
{
	unsigned long long	nb;
	int					lenght;

	lenght = 0;
	if (nbr < 0)
	{
		nb = nbr * -1;
		lenght++;
	}
	else
		nb = nbr;
	while (nb >= (unsigned)base_lenght)
	{
		nb /= base_lenght;
		lenght++;
	}
	lenght++;
	return (lenght);
}

static char	*ft_convert_nbr_base(unsigned long long a,
	int base, char *res, int i)
{
	while (a != 0)
	{
		if ((a % base) < 10)
			res[i - 1] = (a % base) + 48;
		else
			res[i - 1] = (a % base) + 55;
		a /= base;
		i--;
	}
	return (res);
}

int	ft_printf_base(unsigned long long nbr, int base, int lower)
{
	char	*res;
	int		res_lenght;
	int		c;

	if (nbr == 0)
		return (ft_printf_putchar('0'));
	res_lenght = ft_lenght_nbr(nbr, base);
	res = malloc(sizeof(char) * (res_lenght + 1));
	if (!res)
		return (-1);
	res = ft_convert_nbr_base(nbr, base, res, res_lenght);
	res[res_lenght] = '\0';
	c = ft_printf_putstr(res, lower);
	free(res);
	return (c);
}
