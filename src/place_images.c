/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:35:37 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 12:21:20 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void place_image(t_game *game, char **matrix, char **new_matrix, char *image, char character)
{
	int x;
	int y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == character)
			{
				if (mlx_image_to_window(game->mlx, image, y * PIXELS, x * PIXELS) < 0)
					error_msg("Error loading the image", matrix, new_matrix);
			}
			y++;
		}
		x++;
	}
}

void	place_images(t_game *game, char **matrix, char **new_matrix)
{
	place_image(game, matrix, new_matrix, game->background, '0');
	place_image(game, matrix, new_matrix, game->tree, '1');
	place_image(game, matrix, new_matrix, game->closed_door, 'E');
	place_image(game, matrix, new_matrix, game->door, 'E');
	place_image(game, matrix, new_matrix, game->crystal, 'C');
	place_image(game, matrix, new_matrix, game->reptile, 'P');
	game->str_moves = mlx_put_string(game->mlx, "Moves:", 25, 25);
	game->str_count = mlx_put_string(game->mlx, "0", 90, 25);
}
