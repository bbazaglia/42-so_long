/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:29:05 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 11:33:20 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

#include <game.h>

typedef struct s_object{
    int             id;
    t_coord         pos[1];
    t_image         *img;
}t_object;

extern t_object *object_push(int id, t_coord pos, t_image *img);
extern void     object_set(t_object *set, int id, t_coord pos, t_image *img);

#endif