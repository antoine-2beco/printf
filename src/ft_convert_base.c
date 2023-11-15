/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:29:59 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/15 14:20:34 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenght_nbr(int nbr, char *base)
{
	int				base_lenght;
	unsigned int	nb;
	int				lenght;

	lenght = 0;
	base_lenght = ft_strlen(base);
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

char	*ft_convert_base(unsigned int nbr)
{
	char	*res;
	int		res_lenght;

	if (!nbr)
		return (NULL);

	res_lenght = ft_lenght_nbr(nbr, "0123456789abcdef");
	res = malloc(sizeof(char) * (res_lenght) + 1);
	if (!res)
		return (NULL);
	res = ft_convert_nbr_base(nbr, "0123456789abcdef", res, res_lenght);
	res[res_lenght] = '\0';
	return (res);
}
