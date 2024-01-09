/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:59:38 by ade-beco          #+#    #+#             */
/*   Updated: 2024/01/09 18:03:12 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include "libft/libft.h"

// common
int		ft_printf(const char *str, ...);
int		ft_printf_base(unsigned long long nbr, int base, int lower);


// utils
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *s, int lower);


#endif