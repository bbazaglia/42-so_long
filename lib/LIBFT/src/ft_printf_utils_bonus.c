/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:28:46 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/19 09:27:17 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[count])
		ft_putchar(str[count++]);
	return (count);
}

int	ft_putnbr(int n)
{
	size_t	num;
	int		count;

	num = (size_t)n;
	count = 0;
	if (n < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	return (count);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	size_t	num;
	int		count;

	num = (size_t)n;
	count = 0;
	if (n < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num < 10)
		count += ft_putchar(num + '0');
	else
	{
		count += ft_unsigned_putnbr(num / 10);
		count += ft_unsigned_putnbr(num % 10);
	}
	return (count);
}

int	ft_puthex(size_t num, char specifier)
{
	unsigned int	count;
	char			*hex;

	if (specifier == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	count = 0;
	if (num < 16)
		count += ft_putchar(hex[num]);
	else
	{
		count += ft_puthex(num / 16, specifier);
		count += ft_puthex(num % 16, specifier);
	}
	return (count);
}

int	ft_putptr(size_t ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex((size_t)ptr, 'x');
	return (count);
}
