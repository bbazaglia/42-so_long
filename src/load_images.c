/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:34:28 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/31 15:13:13 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game, char **matrix, char **new_matrix)
{
	game->background_t = mlx_load_png("./img/x4/grass.png");
	game->reptile_t = mlx_load_png("./img/x4/reptile_front.png");
	game->tree_t = mlx_load_png("./img/x4/tree.png");
	game->crystal_t = mlx_load_png("./img/x4/crystal.png");
	game->door_t = mlx_load_png("./img/x4/door.png");
	game->closed_door_t = mlx_load_png("./img/x4/closed_door.png");
	if (!game->background_t || !game->reptile_t || !game->tree_t
		|| !game->crystal_t || !game->door_t || !game->closed_door_t)
		error_msg("Error loading the texture", matrix, new_matrix);
	game->background = mlx_texture_to_image(game->mlx, game->background_t);
	game->reptile = mlx_texture_to_image(game->mlx, game->reptile_t);
	game->tree = mlx_texture_to_image(game->mlx, game->tree_t);
	game->crystal = mlx_texture_to_image(game->mlx, game->crystal_t);
	game->door = mlx_texture_to_image(game->mlx, game->door_t);
	game->closed_door = mlx_texture_to_image(game->mlx, game->closed_door_t);
	place_images(game, matrix, new_matrix);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->reptile);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->crystal);
	mlx_delete_image(game->mlx, game->door);
	mlx_delete_image(game->mlx, game->closed_door);
	mlx_delete_image(game->mlx, game->str_count);
	mlx_delete_image(game->mlx, game->str_moves);
	mlx_delete_texture(game->reptile_t);
	mlx_delete_texture(game->tree_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->crystal_t);
	mlx_delete_texture(game->door_t);
	mlx_delete_texture(game->closed_door_t);
}
