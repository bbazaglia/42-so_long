/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:32:59 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 11:40:09 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

// create instances of a t_object struct
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

// update the attributes of a t_object struct
void    object_set(t_object *set, int id, t_coord pos, t_image *img)
{
    if (!set)
        return ;
    set->id = id;
    set->pos[0] = pos;
    set->img = img;
}