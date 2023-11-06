/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:35 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/06 10:14:13 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_game *game)
{
	game->background_t = mlx_load_png("./img/x4/grass.png");
	game->reptile_t = mlx_load_png("./img/x4/reptile_front.png");
	game->tree_t = mlx_load_png("./img/x4/tree.png");
	game->door_t = mlx_load_png("./img/x4/door.png");
	game->closed_door_t = mlx_load_png("./img/x4/closed_door.png");
	game->flame_t = mlx_load_png("./img/x4/flame.png");
	game->crystal_t = mlx_load_png("./img/x4/crystal.png");
	if (!game->background_t || !game->reptile_t || !game->tree_t
		|| !game->door_t || !game->closed_door_t || !game->flame_t
		|| !game->crystal_t)
		error_msg("Error loading the texture", game);
	game->background = mlx_texture_to_image(game->mlx, game->background_t);
	game->reptile = mlx_texture_to_image(game->mlx, game->reptile_t);
	game->tree = mlx_texture_to_image(game->mlx, game->tree_t);
	game->door = mlx_texture_to_image(game->mlx, game->door_t);
	game->closed_door = mlx_texture_to_image(game->mlx, game->closed_door_t);
	game->flame = mlx_texture_to_image(game->mlx, game->flame_t);
	game->crystal = mlx_texture_to_image(game->mlx, game->crystal_t);
	place_images(game);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->reptile);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->door);
	mlx_delete_image(game->mlx, game->closed_door);
	mlx_delete_image(game->mlx, game->str_count);
	mlx_delete_image(game->mlx, game->str_moves);
	mlx_delete_image(game->mlx, game->crystal);
	mlx_delete_image(game->mlx, game->flame);
	mlx_delete_texture(game->reptile_t);
	mlx_delete_texture(game->tree_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->door_t);
	mlx_delete_texture(game->closed_door_t);
	mlx_delete_texture(game->crystal_t);
	mlx_delete_texture(game->flame_t);
}
