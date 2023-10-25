/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:34:28 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 10:34:34 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game, char **matrix, char **new_matrix)
{
	load_background(game, matrix, new_matrix);
	load_reptile(game, matrix, new_matrix);
	load_tree(game, matrix, new_matrix);
	load_crystal(game, matrix, new_matrix);
	load_door(game, matrix, new_matrix);
	place_images(game, matrix, new_matrix);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->reptile);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->crystal);
	mlx_delete_image(game->mlx, game->door);
	mlx_delete_texture(game->reptile_t);
	mlx_delete_texture(game->tree_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->crystal_t);
	mlx_delete_texture(game->door_t);
}
