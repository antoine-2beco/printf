/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/20 14:48:18 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include <stdio.h>

// common
int		ft_printf(const char *str, ...);
int		ft_base(unsigned long long nbr, int base, int lower);
int		ft_treat_void(long long int nbr);
int		ft_treat_dec(long long int nbr);
int		ft_treat_hexa(long long int nbrm, int lower);

// utils
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int	ft_putstrtolower(char const *s);

#endif