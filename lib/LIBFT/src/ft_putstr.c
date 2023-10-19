/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:31:39 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/19 09:28:51 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count);
}
