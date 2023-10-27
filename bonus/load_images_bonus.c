/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:35 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/27 14:00:18 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_game *game, char **matrix, char **new_matrix)
{
	load_background(game, matrix, new_matrix);
	load_reptile(game, matrix, new_matrix);
	load_tree(game, matrix, new_matrix);
	load_flowers(game, matrix, new_matrix);
	load_door(game, matrix, new_matrix);
	load_flame(game, matrix, new_matrix);
	place_images(game, matrix, new_matrix);
}

void	load_flame(t_game *game, char **matrix, char **new_matrix)
{
	game->flame_t = mlx_load_png("./img/x4/flame.png");
	if (!game->flame_t)
		error_msg("Error loading the flame texture", matrix, new_matrix);
	game->flame = mlx_texture_to_image(game->mlx, game->flame_t);
}

void	place_flame(t_game *game, char **matrix, char **new_matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'F')
			{
				if (mlx_image_to_window(game->mlx, game->flame, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading flame image", matrix, new_matrix);
			}
			y++;
		}
		x++;
	}
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
	mlx_delete_image(game->mlx, game->flower1);
	mlx_delete_image(game->mlx, game->flower2);
	mlx_delete_image(game->mlx, game->flower3);
	mlx_delete_image(game->mlx, game->flower4);
	mlx_delete_image(game->mlx, game->flame);
	mlx_delete_texture(game->reptile_t);
	mlx_delete_texture(game->tree_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->door_t);
	mlx_delete_texture(game->closed_door_t);
	mlx_delete_texture(game->flower1_t);
	mlx_delete_texture(game->flower2_t);
	mlx_delete_texture(game->flower3_t);
	mlx_delete_texture(game->flower4_t);
	mlx_delete_texture(game->flame_t);
}