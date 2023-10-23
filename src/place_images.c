#include "so_long.h"

void	place_images(t_game *game, char **matrix)
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
				error_msg("Error loading the background image", matrix);
			y++;
		}
		x++;
	}
    place_tree(game, matrix);
    place_door(game, matrix);
    place_crystals(game, matrix);
    place_reptile(game, matrix);
}

void	place_tree(t_game *game, char **matrix)
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
					error_msg("Error loading the tree image", matrix);
			}
			y++;
		}
		x++;
	}
}

void	place_door(t_game *game, char **matrix)
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
				if (mlx_image_to_window(game->mlx, game->door, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("Error loading the door image", matrix);
			}
			y++;
		}
		x++;
	}
}

void	place_crystals(t_game *game, char **matrix)
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
					error_msg("Error loading the crystal image", matrix);
			}
			y++;
		}
		x++;
	}
}

void	place_reptile(t_game *game, char **matrix)
{
	int x;
	int y;

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
					error_msg("Error loading the reptile image", matrix);
			}
			y++;
		}
		x++;
	}
}