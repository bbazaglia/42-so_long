/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:35 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 12:19:16 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_image(t_game *game, void **image, const char *file_path)
{
	*image = mlx_load_png(file_path);
	if (!*image)
		error_msg("Error loading the texture", game);
	*image = mlx_texture_to_image(game->mlx, *image);
}

void	delete_image(t_game *game, void *image)
{
	mlx_delete_image(game->mlx, image);
}

void	load_images(t_game *game)
{
	load_image(game, &game->background_t, "./img/x4/grass.png");
	load_image(game, &game->reptile_t, "./img/x4/reptile_front.png");
	load_image(game, &game->tree_t, "./img/x4/tree.png");
	load_image(game, &game->door_t, "./img/x4/door.png");
	load_image(game, &game->closed_door_t, "./img/x4/closed_door.png");
	load_image(game, &game->flame_t, "./img/x4/flame.png");
	load_image(game, &game->crystal_t, "./img/x4/crystal.png");
	place_images(game);
}

void	delete_images(t_game *game)
{
	delete_image(game, game->background);
	delete_image(game, game->reptile);
	delete_image(game, game->tree);
	delete_image(game, game->door);
	delete_image(game, game->closed_door);
	delete_image(game, game->flame);
	delete_image(game, game->crystal);
	delete_image(game, game->str_count);
	delete_image(game, game->str_moves);
}
