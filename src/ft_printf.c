/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/15 15:17:46 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_specifics(const char *str, int i, va_list args)
{
	if (str[i] == '%' && str[i + 1] == 'c')
		ft_putchar((char)(va_arg(args, int)));
	else if (str[i] == '%' && str[i + 1] == 's')
		ft_putstr((char *)va_arg(args, char *));
	else if (str[i] == '%' && str[i + 1] == 'p')
	{
		ft_putstr("0x10");
		ft_putstr(ft_base((unsigned int)va_arg(args, void *), 16));
	}
	else if (str[i] == '%' && str[i + 1] == 'd')
		ft_putstr(ft_base((int)va_arg(args, int), 10));
	else if (str[i] == '%' && str[i + 1] == 'i')
		ft_putstr(ft_base((int)va_arg(args, int), 10));
	else if (str[i] == '%' && str[i + 1] == 'u')
		ft_putstr(ft_base((unsigned int)va_arg(args, unsigned int), 10));
	else if (str[i] == '%' && str[i + 1] == 'x')
		ft_putstr(ft_base((unsigned int)va_arg(args, unsigned int), 16));
	else if (str[i] == '%' && str[i + 1] == 'X')
		ft_putstr(ft_base((unsigned int)va_arg(args, unsigned int), 16.5));
	else if (str[i] == '%' && str[i + 1] == '%')
		ft_putchar('%');
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list			args;

	i = -1;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (!ft_specifics(str, i, args))
			ft_putchar(str[i]);
		else
			i++;
	}
	va_end(args);
	return (1);
}

/*int	main(void)
{
	char	x = 'i';
	char	*y = "Hello World !";
	void	*z = "t";
	int		i = 5489;
	unsigned int	u = 789;
	ft_printf("%c %s %p %d %i %u %x %X %%", x, y, z, i, i, u, i, i);
	write(1, "\n", 1);
	printf("%c %s %p %d %i %u %x %X %%", x, y, z, i, i, u, i, i);

}*/
