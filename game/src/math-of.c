/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:22:47 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 12:23:11 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math-of.h>

t_coord coord_start(int x, int y)
{
    t_coord set;

    set.x = x;
    set.y = y;
    return (set);
}
