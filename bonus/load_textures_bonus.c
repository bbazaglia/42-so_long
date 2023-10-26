/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:10 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 15:27:39 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_background(t_game *game, char **matrix, char **new_matrix)
{
	game->background_t = mlx_load_png("./img/x4/grass.png");
	if (!game->background_t)
		error_msg("Error loading the background texture", matrix, new_matrix);
	game->background = mlx_texture_to_image(game->mlx, game->background_t);
}

void	load_reptile(t_game *game, char **matrix, char **new_matrix)
{
	game->reptile_t = mlx_load_png("./img/x4/reptile_front.png");
	if (!game->reptile_t)
		error_msg("Error loading the reptile texture", matrix, new_matrix);
	game->reptile = mlx_texture_to_image(game->mlx, game->reptile_t);
}

void	load_tree(t_game *game, char **matrix, char **new_matrix)
{
	game->tree_t = mlx_load_png("./img/x4/tree.png");
	if (!game->tree_t)
		error_msg("Error loading the tree texture", matrix, new_matrix);
	game->tree = mlx_texture_to_image(game->mlx, game->tree_t);
}

void	load_door(t_game *game, char **matrix, char **new_matrix)
{
	game->door_t = mlx_load_png("./img/x4/door.png");
	if (!game->door_t)
		error_msg("Error loading the door texture", matrix, new_matrix);
	game->door = mlx_texture_to_image(game->mlx, game->door_t);
	game->closed_door_t = mlx_load_png("./img/x4/closed_door.png");
	if (!game->closed_door_t)
		error_msg("Error loading the door texture", matrix, new_matrix);
	game->closed_door = mlx_texture_to_image(game->mlx, game->closed_door_t);
}

void	load_flowers(t_game *game, char **matrix, char **new_matrix)
{
	game->flower1_t = mlx_load_png("./img/x4/flower1.png");
	if (!game->flower1_t)
		error_msg("Error loading the flower texture", matrix, new_matrix);
	game->flower1 = mlx_texture_to_image(game->mlx, game->flower1_t);
	game->flower2_t = mlx_load_png("./img/x4/flower2.png");
	if (!game->flower2_t)
		error_msg("Error loading the flower texture", matrix, new_matrix);
	game->flower2 = mlx_texture_to_image(game->mlx, game->flower2_t);
	game->flower3_t = mlx_load_png("./img/x4/flower3.png");
	if (!game->flower3_t)
		error_msg("Error loading the flower texture", matrix, new_matrix);
	game->flower3 = mlx_texture_to_image(game->mlx, game->flower3_t);
	game->flower4_t = mlx_load_png("./img/x4/flower4.png");
	if (!game->flower4_t)
		error_msg("Error loading the flower texture", matrix, new_matrix);
	game->flower4 = mlx_texture_to_image(game->mlx, game->flower4_t);
}
