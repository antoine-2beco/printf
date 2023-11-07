/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:07 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/02 17:46:05 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_

int	ft_printf(const char *str, ...)
{
	unsigned int	i;
	va_list 		args;
	void			*temp;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) && !(str[i] == '%'))
			ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (str[i + 1] == 'c')
			{
				temp = (char *)(va_arg(args, char *));
				write(1, &temp, 1);
			}
			else if (str[i + 1] == 's')
			{
				temp = (char *)va_arg(args, char *);
				ft_putstr(temp);
			}
			else if (str[i + 1] == 'p')
			{
				temp = va_arg(args, uint8_t *);
				write (1, &temp, sizeof(temp));
			}
			i++;
		}
		i++;
		va_end(args);
	}
	return (1);
}

int	main()
{
	char x = 'i';
	char *y = "Hello World !";
	ft_printf("%c\n%", x, y);
}
