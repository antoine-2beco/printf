/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:29:59 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/15 17:25:03 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenght_nbr(int nbr, int base_lenght)
{
	unsigned int	nb;
	int				lenght;

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

static char	*ft_convert_nbr_base(long a, char *base, char *res, int i)
{
	int	l;

	l = ft_strlen(base);
	if (a < 0)
	{
		a = -a;
		res[0] = '-';
	}
	i--;
	while (a >= l)
	{
		res[i] = base[a % l];
		a /= l;
		i--;
	}
	if (a < l)
		res[i] = base[a];
	return (res);
}

int	ft_base(long long int nbr, float base)
{
	char	*res;
	int		res_lenght;
	int		c;

	if (!nbr)
		return (0);
	res_lenght = ft_lenght_nbr(nbr, base);
	res = malloc(sizeof(char) * (res_lenght + 1));
	if (!res)
		return (0);
	if (base == 16)
		res = ft_convert_nbr_base(nbr, "0123456789abcdef", res, res_lenght);
	else if (base == 16.5)
		res = ft_convert_nbr_base(nbr, "0123456789ABCDEF", res, res_lenght);
	else if (base == 10)
		res = ft_convert_nbr_base(nbr, "0123456789", res, res_lenght);
	else
		return (0);
	res[res_lenght] = '\0';
	c = ft_putstr(res);
	free(res);
	return (c);
}
