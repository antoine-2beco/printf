/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/15 14:55:42 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include <stdio.h>

// common
void	ft_putchar(char a);
char	*ft_base(long long int nbr, float base);

// utils
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);


#endif