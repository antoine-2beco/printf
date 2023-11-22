/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:39:09 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/22 15:15:38 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_putstr(char *s, int lower)
{
	int	l;
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!s)
		return (ft_putstr("(null)", 0));
	l = ft_strlen(s);
	while (i < l)
	{
		if (lower)
			s[i] = ft_tolower(s[i]);
		if (ft_putchar(s[i++]) == -1)
			return (-1);
		c++;
	}
	return (c);
}
