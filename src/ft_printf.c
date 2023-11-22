/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/22 16:11:15 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static int	ft_specifics(const char *str, int i, va_list arg)
{
	int	j;

	if (str[i] == '%' && str[i + 1] == 'c')
		j = ft_putchar((char)(va_arg(arg, int)));
	else if (str[i] == '%' && str[i + 1] == 's')
		j = ft_putstr((char *)va_arg(arg, char *), 0);
	else if (str[i] == '%' && str[i + 1] == 'p')
		j = ft_treat_void(va_arg(arg, unsigned long long));
	else if (str[i] == '%' && str[i + 1] == 'd')
		j = ft_treat_dec(va_arg(arg, int));
	else if (str[i] == '%' && str[i + 1] == 'i')
		j = ft_treat_dec(va_arg(arg, int));
	else if (str[i] == '%' && str[i + 1] == 'u')
		j = ft_treat_dec(va_arg(arg, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'x')
		j = ft_base(va_arg(arg, unsigned int), 16, 1);
	else if (str[i] == '%' && str[i + 1] == 'X')
		j = ft_base(va_arg(arg, unsigned int), 16, 0);
	else if (str[i] == '%' && str[i + 1] == '%')
		j = ft_putchar('%');
	else
		return (-2);
	return (j);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			arg;
	int				c;
	int				j;

	i = -1;
	c = 0;
	va_start(arg, str);
	while (str[++i] != '\0')
	{
		j = ft_specifics(str, i, arg);
		if (j == -2 && ft_putchar(str[i]) != -1)
			c++;
		else if (j != -1 && j != -2)
		{
			c += j;
			i++;
		}
		else
			return (-1);
	}
	va_end(arg);
	return (c);
}

/*int	main(void)
{
	ft_printf("%X", 123456);
	printf("\n%X", 123456);
}
*/