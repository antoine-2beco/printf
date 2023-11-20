/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/20 14:37:45 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static int	ft_specifics(const char *str, int i, va_list arg, unsigned int *c)
{
	if (str[i] == '%' && str[i + 1] == 'c')
		*c += ft_putchar((char)(va_arg(arg, int)));
	else if (str[i] == '%' && str[i + 1] == 's')
		*c += ft_putstr((char *)va_arg(arg, char *));
	else if (str[i] == '%' && str[i + 1] == 'p')
		*c += ft_treat_void(va_arg(arg, unsigned long long));
	else if (str[i] == '%' && str[i + 1] == 'd')
		*c += ft_treat_dec(va_arg(arg, int));
	else if (str[i] == '%' && str[i + 1] == 'i')
		*c += ft_treat_dec(va_arg(arg, int));
	else if (str[i] == '%' && str[i + 1] == 'u')
		*c += ft_treat_dec(va_arg(arg, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'x')
		*c += ft_treat_hexa(va_arg(arg, int), 1);
	else if (str[i] == '%' && str[i + 1] == 'X')
		*c += ft_treat_hexa(va_arg(arg, int), 0);
	else if (str[i] == '%' && str[i + 1] == '%')
		*c += ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			arg;
	unsigned int	c;

	i = -1;
	c = 0;
	va_start(arg, str);
	while (str[++i] != '\0')
	{
		if (!ft_specifics(str, i, arg, &c))
			c += ft_putchar(str[i]);
		else
			i++;
	}
	va_end(arg);
	return (c);
}

int	main(void)
{
	void	*p;

	p = "khjkhjg";

	ft_printf(" %p ", (void *)0);
	printf("\n %p \n\n", (void *)0);

	ft_printf(" %x ", -1);
	printf("\n %x ", -1);
}