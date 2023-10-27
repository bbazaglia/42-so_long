/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:28:52 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/27 16:23:02 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	place_images(t_game *game, char **matrix, char **new_matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (mlx_image_to_window(game->mlx, game->background, y * PIXELS, x
					* PIXELS) < 0)
				error_msg("loading background image", matrix, new_matrix);
			y++;
		}
		x++;
	}
	place_tree(game, matrix, new_matrix);
	place_door(game, matrix, new_matrix);
	place_flowers(game, matrix, new_matrix);
	place_reptile(game, matrix, new_matrix);
	place_flame(game, matrix, new_matrix);
	game->str_moves = mlx_put_string(game->mlx, "Moves:", 25, 25);
	game->str_count = mlx_put_string(game->mlx, "0", 90, 25);
}

void	place_tree(t_game *game, char **matrix, char **new_matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->tree, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading flame image", matrix, new_matrix);
			}
			y++;
		}
		x++;
	}
}

void	place_door(t_game *game, char **matrix, char **new_matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'E')
			{
				if ((mlx_image_to_window(game->mlx, game->closed_door, y
							* PIXELS, x * PIXELS) < 0)
					|| (mlx_image_to_window(game->mlx, game->door, y * PIXELS, x
							* PIXELS) < 0))
					error_msg("loading door image", matrix, new_matrix);
				game->door->instances[0].enabled = false;
			}
			y++;
		}
		x++;
	}
}

void	place_flowers(t_game *game, char **matrix, char **new_matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'C')
			{
				if ((mlx_image_to_window(game->mlx, game->flower[3], y * PIXELS, x
							* PIXELS) < 0) || (mlx_image_to_window(game->mlx,
							game->flower[2], y * PIXELS, x * PIXELS) < 0)
					|| (mlx_image_to_window(game->mlx, game->flower[1], y
							* PIXELS, x * PIXELS) < 0)
					|| (mlx_image_to_window(game->mlx, game->flower[0], y
							* PIXELS, x * PIXELS) < 0))
					error_msg("loading flowers images", matrix, new_matrix);
			}
			y++;
		}
		x++;
	}
}

void	place_reptile(t_game *game, char **matrix, char **new_matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->reptile, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading reptile image", matrix, new_matrix);
			}
			y++;
		}
		x++;
	}
}
