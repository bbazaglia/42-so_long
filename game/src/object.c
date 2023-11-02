/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:32:59 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 13:36:00 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>
#include <stdlib.h>

t_object *object_push(int id, t_coord pos, t_image *img)
{
    t_object    *set;

    set = (t_object *)malloc(sizeof(t_object));
    if (!set)
        return (NULL);
    set->id = id;
    set->pos[0] = pos;
    set->img = img;
    return (set);
}

void    object_set(t_object *set, int id, t_coord pos, t_image *img)
{
    if (!set)
        return ;
    set->id = id;
    set->pos[0] = pos;
    set->img = img;
}