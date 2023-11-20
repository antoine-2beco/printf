/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:18:11 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/20 14:48:15 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	ft_putstrtolower(char const *s)
{
	unsigned int	i;
	char			*out;
	int				c;

	if (!s)
		return (NULL);
	i = 0;
	out = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!out)
		return (NULL);
	while (s[i] != '\0')
	{
		out[i] = ft_tolower(s[i]);
		i++;
	}
	out[i] = '\0';
	c = ft_putstr(out);
	free(out);
	return (c);
}
