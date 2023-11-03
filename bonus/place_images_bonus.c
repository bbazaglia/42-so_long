/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:28:52 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 12:07:41 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void place_image(t_game *game, void *image, char character)
{
   int x;
   int y;

   x = 0;
   while (game->matrix[x])
   {
       y = 0;
       while (game->matrix[x][y])
       {
           if (game->matrix[x][y] == character)
           {
               if (mlx_image_to_window(game->mlx, image, y * PIXELS, x * PIXELS) < 0)
                  error_msg("loading image", game);
           }
           y++;
       }
       x++;
   }
}

void place_images(t_game *game)
{
   place_image(game, game->background, '0');
   place_image(game, game->tree, '1');
   place_image(game, game->closed_door, 'E');
   place_image(game, game->door, 'E');
   place_image(game, game->crystal, 'C');
   place_image(game, game->reptile, 'P');
   place_image(game, game->flame, 'F');
   game->str_moves = mlx_put_string(game->mlx, "Moves:", 25, 25);
   game->str_count = mlx_put_string(game->mlx, "0", 90, 25);
}
