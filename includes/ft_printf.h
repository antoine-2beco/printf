/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/22 16:58:06 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// common
int		ft_printf(const char *str, ...);
int		ft_base(unsigned long long nbr, int base, int lower);
int		ft_treat_void(long long int nbr);
int		ft_treat_dec(long long int nbr);
int		ft_atoi(const char *str);

// utils
int		ft_putchar(char c);
int		ft_putstr(char *s, int lower);
int		ft_strlen(const char *s);

#endif