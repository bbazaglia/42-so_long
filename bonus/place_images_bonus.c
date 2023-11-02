/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:28:52 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/02 13:54:02 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	place_tree(game);
	place_door(game);
	place_crystal(game);
	place_reptile(game);
	place_flame(game);
	game->str_moves = mlx_put_string(game->mlx, "Moves:", 25, 25);
	game->str_count = mlx_put_string(game->mlx, "0", 90, 25);
}

void	place_tree(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (game->matrix[x][y] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->tree, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading flame image", game);
			}
			y++;
		}
		x++;
	}
}

void	place_door(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (game->matrix[x][y] == 'E')
			{
				if ((mlx_image_to_window(game->mlx, game->closed_door, y
							* PIXELS, x * PIXELS) < 0)
					|| (mlx_image_to_window(game->mlx, game->door, y * PIXELS, x
							* PIXELS) < 0))
					error_msg("loading door image", game);
				game->door->instances[0].enabled = false;
			}
			y++;
		}
		x++;
	}
}

void	place_crystal(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (game->matrix[x][y] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->crystal, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading crystal image", game);
			}
			y++;
		}
		x++;
	}
}

void	place_reptile(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (game->matrix[x][y] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->reptile, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading reptile image", game);
			}
			y++;
		}
		x++;
	}
}
