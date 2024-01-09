/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:54:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/09 17:58:54 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf_putstr(char *s, int lower)
{
	int	l;
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!s)
		return (ft_printf_putstr("(null)", 0));
	l = ft_strlen(s);
	while (i < l)
	{
		if (lower)
			s[i] = ft_tolower(s[i]);
		if (ft_printf_putchar(s[i++]) == -1)
			return (-1);
		c++;
	}
	return (c);
}