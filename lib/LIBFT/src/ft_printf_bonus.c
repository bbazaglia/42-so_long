/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:27:47 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/19 09:27:08 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

void	find_flags(const char **format, t_flags *flags)
{
	flags->hash_flag = 0;
	flags->plus_flag = 0;
	flags->space_flag = 0;
	while (**format == '#' || **format == '+' || **format == ' ')
	{
		if (**format == '#')
			flags->hash_flag = 1;
		else if (**format == '+')
			flags->plus_flag = 1;
		else if (**format == ' ')
			flags->space_flag = 1;
		(*format)++;
	}
}

int	print_decimal(va_list ap, const t_flags *flags)
{
	int	count;
	int	num;

	count = 0;
	num = va_arg(ap, int);
	if (num >= 0)
	{
		if (flags->plus_flag)
			count += ft_putchar('+');
		else if (flags->space_flag)
			count += ft_putchar(' ');
	}
	count += ft_putnbr(num);
	return (count);
}

int	print_hex(char specifier, va_list ap, const t_flags *flags)
{
	int				count;
	unsigned int	unsigned_num;

	count = 0;
	unsigned_num = va_arg(ap, unsigned int);
	if (flags->hash_flag && unsigned_num != 0 && specifier == 'x')
		count += ft_putstr("0x");
	else if (flags->hash_flag && unsigned_num != 0 && specifier == 'X')
		count += ft_putstr("0X");
	count += ft_puthex(unsigned_num, specifier);
	return (count);
}

int	print_format(char specifier, va_list ap, const t_flags *flags)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_decimal(ap, flags);
	else if (specifier == 'u')
		count += ft_unsigned_putnbr(va_arg(ap, unsigned int));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, size_t));
	else if (specifier == 'x' || specifier == 'X')
		count += print_hex(specifier, ap, flags);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	t_flags	flags;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			find_flags(&format, &flags);
			count += print_format(*format, ap, &flags);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
