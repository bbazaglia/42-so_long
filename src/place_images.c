/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:35:37 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/06 10:21:12 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check bonus (/bonus/place_image_bonus) to see an improved version of this code

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
				error_msg("Error loading the background image",
					matrix, new_matrix);
			y++;
		}
		x++;
	}
	place_tree(game, matrix, new_matrix);
	place_door(game, matrix, new_matrix);
	place_crystals(game, matrix, new_matrix);
	place_reptile(game, matrix, new_matrix);
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
					error_msg("Error loading the tree image",
						matrix, new_matrix);
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
				if (mlx_image_to_window(game->mlx, game->closed_door, y
						* PIXELS, x * PIXELS) < 0)
					error_msg("Error loading the door image",
						matrix, new_matrix);
				if (mlx_image_to_window(game->mlx, game->door, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("Error loading the door image",
						matrix, new_matrix);
				game->door->instances[0].enabled = false;
			}
			y++;
		}
		x++;
	}
}

void	place_crystals(t_game *game, char **matrix, char **new_matrix)
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
				if (mlx_image_to_window(game->mlx, game->crystal, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("Error loading the crystal image",
						matrix, new_matrix);
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
					error_msg("Error loading the reptile image",
						matrix, new_matrix);
			}
			y++;
		}
		x++;
	}
}


void	place_image(t_game *game, void *image, char character)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (game->matrix[x][y] == character)
			{
				if (mlx_image_to_window(game->mlx, image, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading image", game);
			}
			y++;
		}
		x++;
	}
}

void	place_images(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (mlx_image_to_window(game->mlx, game->background, y * PIXELS, x
					* PIXELS) < 0)
				error_msg("loading background image", game);
			y++;
		}
		x++;
	}
	place_image(game, game->tree, '1');
	place_image(game, game->door, 'E');
	place_image(game, game->closed_door, 'E');
	place_image(game, game->crystal, 'C');
	place_image(game, game->reptile, 'P');
	game->str_moves = mlx_put_string(game->mlx, "Moves:", 25, 25);
	game->str_count = mlx_put_string(game->mlx, "0", 90, 25);
}
