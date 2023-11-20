/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by ade-beco          #+#    #+#             */
/*   Updated: 2023/11/20 13:17:16 by ade-beco         ###   ########.fr       */
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
int		ft_treat_dec(char *nbr);
int		ft_treat_void(unsigned long long nbr);

// utils
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strtolower(char const *s);

#endif