/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:18:56 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 11:18:28 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

typedef struct s_coord{
    int x;
    int y;
}t_coord;

t_coord coord_start(int x, int y);

#endif