/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:48:28 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/19 11:47:14 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../include/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putstr(char *str);
int	ft_putptr(size_t ptr);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_puthex(size_t num, char type);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif
