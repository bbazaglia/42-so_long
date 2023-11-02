/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:24:24 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 14:28:01 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <chained.h>
#include <image.h>
#include <math-of.h>
#include <object.h>

typedef struct s_game{
    t_chained *object;
    t_chained *image;
    void      (*object_next_first)(struct s_game *game, t_object *object);
    void      (*object_next_last)(struct s_game *game, t_object *object);
    void      (*object_print)(struct s_game *game);
    void      (*image_next_first)(struct s_game *game, t_image *image);
    void      (*image_next_last)(struct s_game *game, t_image *image);
    t_image   *(*image_search)(struct s_game *game, int id);
    void      (*image_print)(struct s_game *game);
    void      (*pop)(struct s_game *game);
}t_game;

extern void game_set(t_game *set);

#endif