/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:26:33 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 14:30:27 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>
#include <stdio.h>
#include <stdlib.h>

static void game_object_next_first(t_game *set, t_object *object)
{
    chained_next_first(&set->object, chained_push(object));
}

static void game_object_next_last(t_game *set, t_object *object)
{
    chained_next_last(&set->object, chained_push(object));
}

static void game_image_next_first(t_game *set, t_image *image)
{
    chained_next_first(&set->image, chained_push(image));
}

static void game_image_next_last(t_game *set, t_image *image)
{
    chained_next_last(&set->image, chained_push(image));
}

static void game_object_print(t_game *game)
{
    t_chained   *upd;
    t_object    *object;
    int         i;

    upd = game->object;
    i = 0;
    while (upd)
    {
        object = upd->data;
        printf("id %i\n", object->id);
        printf("x %i y %i\n\n", object->pos->x, object->pos->y);
        upd = upd->next;   
    }
}

static void object_pop(t_game *set)
{
    t_chained   *next;
    t_object    *object;

    while (set->object)
    {
        next = set->object->next;
        object = set->object->data;
        free(object);
        free(set->object);
        set->object = next;
    }
}

static void game_image_print(t_game *game)
{
    t_chained   *upd;
    t_image    *image;
    int         i;

    upd = game->image;
    i = 0;
    while (upd)
    {
        image = upd->data;
        printf("id %i\n", image->id);
        upd = upd->next;   
    }
}

static t_image  *game_image_search(t_game *set, int id)
{
    t_chained   *upd;
    t_image     *image;

    upd = set->image;
    while (upd)
    {
        image = upd->data;
        if (image->id == id)
            return (image);
        upd = upd->next;
    }
    return (NULL);
}

static void image_pop(t_game *set)
{
    t_chained   *next;
    t_image     *image;

    while (set->image)
    {
        next = set->image->next;
        image = set->image->data;
        free(image);
        free(set->image);
        set->image = next;
    }
}

static void game_pop(t_game *game)
{
    if (!game)
        return ;
    image_pop(game);
    object_pop(game);
}

void    game_function(t_game *set)
{
    set->object_next_first = game_object_next_first;
    set->object_next_last = game_object_next_last;
    set->object_print = game_object_print;
    set->image_next_first = game_image_next_first;
    set->image_next_last = game_image_next_last;
    set->image_print = game_image_print;
    set->image_search = game_image_search;
    set->pop = game_pop;
}

void game_set(t_game *set)
{
    set->object = NULL;
    set->image = NULL;
    game_function(set);
}